# kuliya for C

Algeria's college hierarchy dataset as a C library

# Get started

Make sure you have both `kuliya.h` and `data.h` files in your path.

```c
#include <stdio.h>
#include "kuliya.h"

int main(void)
{
    kuliya_init();
    kuliya_schema *res = get_node_by_path("umkb/fst/dee/sec");
    if (res != NULL)
    {
        printf("%s\n", res->name.en);
    }
    kuliya_deinit();
}
```

Check practical example usage [here](./example/main.c).

# Contribute

Feel free to ask for help in [#kuliya](https://dzcode.slack.com/archives/C01C0155CKC) group chat
