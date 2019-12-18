#ifndef b_plus_page_hpp
#define b_plus_page_hpp

#define ORDER 5
#define MAX_DATA (ORDER - 1)

class BPlusPage {
public:
    int n;
    int *data;
    BPlusPage **child_ptr;
    BPlusPage *parent_ptr;
    bool leaf;
    BPlusPage *left_ptr, *right_ptr;

    BPlusPage();
    BPlusPage(BPlusPage *other);
    int insert(int element);
    void print();
};

#endif /* b_plus_page_hpp */
