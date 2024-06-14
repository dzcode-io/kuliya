module app;

import std.file : readText, write, exists, remove;
import std.typecons : Nullable;
import asdf;
import std.stdio : writeln, File;
import std.algorithm;
import std.array;
import std.regex;

const string dataPath = "../../_data/";
const string dataFile = "../source/kuliya/data.d";

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

struct Name
{
    string ar;
    string en;
    string fr;
}

struct Terms
{
    int perYear;
    int[] slots;
}

struct Schema
{
    Name name;
    Type type;
    @serdeOptional
    Nullable!Terms terms;
}

void saveToFile(const Schema schema, string path)
{
    // remove ../_data/ prefix and /info.json suffix from path
    const auto pathParts = path.splitter('/').array;
    const auto filePath = pathParts[3 .. $ - 1].join("/");
    // replace / with _ in filePath
    const auto filePathUnderscored = filePath.replace("/", "_");
    File file = File(dataFile, "a");
    file.writeln("immutable Schema ", filePathUnderscored, " = ");
    file.writeln("{");
    file.writeln("    Name(\"", schema.name.ar, "\", \"", schema.name.en, "\", \"", schema.name.fr, "\"),");
    file.writeln("    Type.", schema.type, ",");
    if (schema.terms.isNull)
    {
        file.writeln("    Nullable!Terms.init");
    }
    else
    {
        // file.writeln("    Nullable!Terms({", schema.terms.get.perYear, ", [", schema.terms.get.slots.join(", "), "]});"); // no propery join on const(int[]) error
        file.write("    Nullable!Terms(", schema.terms.get.perYear, ", [", schema
                .terms.get.slots[0]);
        foreach (i, slot; schema.terms.get.slots[1 .. $])
        {
            file.write(", ", slot);
        }
        file.writeln("])");
    }
    file.writeln("};");
    file.writeln();
    file.close();
}

Schema parseInfoJson(string path)
{
    const auto data = readText(path);
    Schema schema;
    schema = asdf.deserialize!Schema(data);
    return schema;
}

void walkDirs(string path)
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

void prepareDataFile()
{
    File file = File(dataFile, "w");
    file.writeln("// This is an auto generated file, do not edit it!");
    file.writeln("module kuliya.data;");
    file.writeln();
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
    file.writeln("struct Name");
    file.writeln("{");
    file.writeln("    string ar;");
    file.writeln("    string en;");
    file.writeln("    string fr;");
    file.writeln("}");
    file.writeln();
    file.writeln("struct Terms");
    file.writeln("{");
    file.writeln("    int perYear;");
    file.writeln("    int[] slots;");
    file.writeln("}");
    file.writeln();
    file.writeln("struct Schema");
    file.writeln("{");
    file.writeln("    Name name;");
    file.writeln("    Type type;");
    file.writeln("    Nullable!Terms terms;");
    file.writeln("}");
    file.writeln();
    file.close();
}

void main()
{
    try
    {
        if (exists(dataFile))
        {
            remove(dataFile);
        }
        prepareDataFile();
        walkDirs(dataPath);
    }
    catch (Exception e)
    {
        import std.stdio : writeln;

        writeln("Error: ", e.msg);
        return;
    }
}
