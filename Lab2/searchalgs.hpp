#include <vector>

std::vector<int> lin_srch(const Student* a, int n, const char* key)
{
    std::vector<int> mtchs = {};
    for (int i = 0; i<n; i++){
        if (strcmp(a[i].name, key) == 0)
            mtchs.push_back(i);
    }
    return mtchs;
}


std::vector<int> bt_srch(const BT_Node* root, const char* key);


std::vector<int> rb_srch(const RB_Node* a, int n, const char* key);


std::vector<int> hash_tb_srch(const Student* a, int n, const char* key);