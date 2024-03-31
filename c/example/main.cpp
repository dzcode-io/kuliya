#include <iostream>
#include <kuliya.h>

class Kuliya
{
public:
    Kuliya();
    ~Kuliya();
    kuliya_schema *GetNodeByPath(const char *path);
};

Kuliya::Kuliya()
{
    kuliya_init();
}

Kuliya::~Kuliya()
{
    kuliya_deinit();
}

kuliya_schema *Kuliya::GetNodeByPath(const char *path)
{
    return get_node_by_path(path);
}

int main(void)
{
    Kuliya *kuliya = new Kuliya();
    auto schema = kuliya->GetNodeByPath("umkb/fst/dee/sec");
    std::cout << schema->name.en << "\n";
}
