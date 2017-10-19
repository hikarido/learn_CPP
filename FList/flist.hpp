#ifndef FLIST_HPP
#define FLIST_HPP

/**
 * @brief The flist class
 * Implement forward single direction list
 */
class flist{

public:
    flist() = default;
    ~flist() = default;

private:
    class Node;
    Node * head = nullptr;

};

#endif //FLIST_HPP
