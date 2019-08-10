#ifndef ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_38_DELETEKTHELEMENT_H
#define ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_38_DELETEKTHELEMENT_H

#include <list>
#include <unordered_map>

namespace sedgewick {

template<typename T>
class Node{
public:
    Node* left_{nullptr};
    Node* right_{nullptr};
    Node* parent_{nullptr};
    T val_;
    int index_{0};
    int leftCnt_{0};
};

template<typename T>
class GeneralizedQueue{
public:
    bool isEmpty() const;
    void insert(T x);
    T remove(int k);

private:
    int index_{0};
    using NodeT = Node<T>;
    NodeT* head_{nullptr};
};

template<typename T>
bool GeneralizedQueue<T>::isEmpty() const {
    return !head_;
}

template<typename T>
void GeneralizedQueue<T>::insert(T x){
//    NodeT newNode = new NodeT;
//    newNode.val_ = x;
//    newNode.index_ = index_;
//    ++index_;
//    if (!head_){
//        head_ = newNode;
//        return;
//    }
//
//    auto currentNode = head_;
//    for(;;){
//        if (currentNode->index_ < newNode.index_){
//            if (!currentNode->right_){
//                currentNode->right_ = newNode;
//                newNode->parent_ = currentNode;
//                break;
//            }
//            currentNode = currentNode->right_;
//        } else {
//            if (!currentNode->left_){
//                currentNode->left_ = newNode;
//                newNode->parent_ = currentNode;
//                break;
//            }
//            currentNode = currentNode->left_;
//        }
//    }
//
//    while (currentNode->parent_){
//        if (currentNode == currentNode->parent_->left_)
//            ++currentNode->parent_->leftCnt_;
//        currentNode = currentNode->parent_;
//    }
}

template <typename T>
T GeneralizedQueue<T>::remove(int k){
    if (!head_)
        return T{};
    NodeT* currentNode = head_;
    for (;;){
        if (currentNode->leftCnt_ == k - 1)
            return currentNode->val_;
        if (currentNode->leftCnt_ > (k - 1))
            currentNode = currentNode->left_;
        else {
            k = k - currentNode->leftCnt_ - 1;
            currentNode = currentNode->right_;
        }
    }
    return T{};
};



}
#endif //ALGORITHMICCHALLENGES_BAGSQUEUESSTACKS_1_3_38_DELETEKTHELEMENT_H
