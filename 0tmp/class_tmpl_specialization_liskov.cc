// cesun, 10/17/20 2:47 PM.

#include <vector>

class Item {

};

class DetailedItem : public Item {

};

class ResourceUser {
public:
    ResourceUser(std::vector<DetailedItem> &ref) : items_ref_{ref} {}

    std::vector<Item> &items_ref_;
};

class ResourceOwner {
public:
    ResourceOwner() : user_{detailed_items_} {}

    ResourceUser user_;
    std::vector<DetailedItem> detailed_items_;
};

int main() {

}

