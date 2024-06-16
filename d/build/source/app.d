/++
This module is responsible for generating the data file from the info.json files.
+/
module app;

import std.file : readText, write, exists, remove;
import std.typecons : Nullable;
import asdf;
import std.stdio : writeln, File;
import std.algorithm;
import std.array;

/++
Data path to the info.json files
+/
const string DATA_PATH = "../../_data/";
/++
Data D file to save the schema
+/
const string DATA_FILE = "../source/kuliya/data.d";

/++
Kuliya types
+/
enum Type
{
    UNIVERSITY,
    ACADEMY,
    PRIVATE_SCHOOL,
    INSTITUTE,
    FACULTY,
    DEPARTMENT,
    SPECIALTY,
    SECTOR
}

/++
Kuliya name
+/
struct Name
{
    /// Arabic name
    string ar;
    /// English name
    string en;
    /// French name
    string fr;
}

/++
Kuliya terms
+/
struct Terms
{
    /// Number of slots per year
    int perYear;
    /// Slots
    int[] slots;
}

/++
Kuliya schema
+/
struct Schema
{
    /// Name
    Name name;
    /// Type
    Type type;
    /// Terms
    @serdeOptional
    Nullable!Terms terms;
}

/++
Save schema to file
Params:
    schema = Schema to save
    path = Path of the info.json file
+/
void saveToFile(const Schema schema, string path) @trusted
{
    // remove ../_data/ prefix and /info.json suffix from path
    const auto pathParts = path.splitter('/').array;
    const auto filePath = pathParts[3 .. $ - 1].join("/");
    // replace / with _ in filePath
    const auto filePathUnderscored = filePath.replace("/", "_");
    File file = File(DATA_FILE, "a");
    file.writeln("immutable Schema ", filePathUnderscored, " = Schema(");
    file.writeln("    Name(\"", schema.name.ar, "\", \"", schema.name.en, "\", \"", schema.name.fr, "\"),");
    file.writeln("    Type.", schema.type, ",");
    if (schema.terms.isNull)
    {
        file.writeln("    Terms.init");
    }
    else
    {
        // file.writeln("    Nullable!Terms({", schema.terms.get.perYear, ", [", schema.terms.get.slots.join(", "), "]});"); // no propery join on const(int[]) error
        file.write("    Terms(", schema.terms.get.perYear, ", [", schema
                .terms.get.slots[0]);
        foreach (i, slot; schema.terms.get.slots[1 .. $])
        {
            file.write(", ", slot);
        }
        file.writeln("])");
    }
    file.writeln(");");
    file.writeln();
    file.close();
}

/++
Parse info.json file to Schema struct
Params:
    path = Path of the info.json file
Returns:
    Schema
+/
Schema parseInfoJson(string path) @trusted
{
    const auto data = readText(path);
    Schema schema;
    schema = asdf.deserialize!Schema(data);
    return schema;
}

/++
Walk through directories and parse info.json files
Params:
    path = Path of the directory
+/
void walkDirs(string path) @trusted
{
    import std.file : DirEntry, dirEntries, isDir, isFile, SpanMode;

    foreach (entry; dirEntries(path, SpanMode.shallow, false))
    {
        if (isDir(entry.name))
        {
            walkDirs(entry.name);
        }
        else if (isFile(entry.name) && entry.name.endsWith("info.json"))
        {
            const auto schema = parseInfoJson(entry.name);
            saveToFile(schema, entry.name);
        }
    }
}

/++
Prepare data file with the schema structure
+/
void prepareDataFile() @trusted
{
    File file = File(DATA_FILE, "w");
    file.writeln("// This is an auto generated file, do not edit it!");
    file.writeln("module kuliya.data;");
    file.writeln();
    file.writeln("import std.typecons : Nullable;");
    file.writeln();
    file.writeln("/++");
    file.writeln("Kuliya types");
    file.writeln("+/");
    file.writeln("enum Type");
    file.writeln("{");
    file.writeln("    UNIVERSITY,");
    file.writeln("    ACADEMY,");
    file.writeln("    PRIVATE_SCHOOL,");
    file.writeln("    INSTITUTE,");
    file.writeln("    FACULTY,");
    file.writeln("    DEPARTMENT,");
    file.writeln("    SPECIALTY,");
    file.writeln("    SECTOR");
    file.writeln("}");
    file.writeln();
    file.writeln("/++");
    file.writeln("Kuliya name");
    file.writeln("+/");
    file.writeln("struct Name");
    file.writeln("{");
    file.writeln("    /// Arabic name");
    file.writeln("    string ar;");
    file.writeln("    /// English name");
    file.writeln("    string en;");
    file.writeln("    /// French name");
    file.writeln("    string fr;");
    file.writeln("}");
    file.writeln();
    file.writeln("/++");
    file.writeln("Kuliya terms");
    file.writeln("+/");
    file.writeln("struct Terms");
    file.writeln("{");
    file.writeln("    /// Number of slots per year");
    file.writeln("    int perYear;");
    file.writeln("    /// Slots");
    file.writeln("    int[] slots;");
    file.writeln("}");
    file.writeln();
    file.writeln("/++");
    file.writeln("Kuliya schema");
    file.writeln("+/");
    file.writeln("struct Schema");
    file.writeln("{");
    file.writeln("    /// Name");
    file.writeln("    Name name;");
    file.writeln("    /// Type");
    file.writeln("    Type type;");
    file.writeln("    /// Terms");
    file.writeln("    Nullable!Terms terms;");
    file.writeln();
    file.writeln("    this(Name name, Type type, Terms terms)");
    file.writeln("    {");
    file.writeln("        this.name = name;");
    file.writeln("        this.type = type;");
    file.writeln("        this.terms = Nullable!Terms(terms);");
    file.writeln("    }");
    file.writeln("}");
    file.writeln();
    file.close();
}

void main() @trusted
{
    try
    {
        if (exists(DATA_FILE))
            remove(DATA_FILE);
        prepareDataFile();
        walkDirs(DATA_PATH);
    }
    catch (Exception e)
    {
        writeln("Error: ", e.msg);
        return;
    }
}
