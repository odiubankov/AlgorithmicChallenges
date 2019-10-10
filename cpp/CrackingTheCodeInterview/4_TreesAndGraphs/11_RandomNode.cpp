#include "11_RandomNode.h"
#include <stdexcept>
#include <random>

void BstRandom::insert(int val){
    if (!root_)
        root_ = std::make_shared<Node>(val);
    else {
        for (auto current = root_; current->val_ != val;) {
            if (current->val_ > val) {
                ++current->leftChildrenCnt_;
                if (!current->left_)
                    current->left_ = std::make_shared<Node>(val);
                current = current->left_;
            } else {
                ++current->rightChildrenCnt_;
                if (!current->right_)
                    current->right_ = std::make_shared<Node>(val);
                current = current->right_;
            }
        }
    }
}

bool BstRandom::find(int val) const {
    return findImpl(root_, val);
}

bool BstRandom::findImpl(const std::shared_ptr<Node>& node, int val) {
    for (auto current = node; current != nullptr;) {
        if (current->val_ == val)
            return true;
        if (current->val_ > val)
            current = current->left_;
        else
            current = current->right_;
    }
    return false;
}

void BstRandom::remove(int val) {
    removeImpl(root_, val);
}

void BstRandom::removeImpl(std::shared_ptr<Node>& node, int val) {
    if (!findImpl(node, val))
        return;
    for (auto current = &node;;) {
        if ((*current)->val_ == val) {
            if ((*current)->right_) {
                auto minRight = (*current)->right_;
                for (; minRight->left_ != nullptr; minRight = minRight->left_);
                (*current)->val_ = minRight->val_;
                --(*current)->rightChildrenCnt_;
                removeImpl((*current)->right_, (*current)->val_);
            } else if ((*current)->left_) {
                (*current)->val_ = (*current)->left_->val_;
                (*current)->leftChildrenCnt_= (*current)->left_->leftChildrenCnt_;
                (*current)->rightChildrenCnt_ = (*current)->left_->rightChildrenCnt_;
                (*current)->right_ = (*current)->left_->right_;
                (*current)->left_ = (*current)->left_->left_;
            } else {
                (*current).reset();
            }
            return;
        }
        if ((*current)->val_ > val) {
            --(*current)->leftChildrenCnt_;
            current = &(*current)->left_;
        } else {
            --(*current)->rightChildrenCnt_;
            current = &(*current)->right_;
        }
    }
}

int BstRandom::getRandom() const {
    static std::default_random_engine generator;
    if (!root_)
        throw std::runtime_error("No items");
    auto itemsCnt = 1 + root_->leftChildrenCnt_ + root_->rightChildrenCnt_;
    auto index = std::uniform_int_distribution<int>{0, itemsCnt - 1}(generator);
    for (auto current = root_;;) {
        if (index == current->leftChildrenCnt_)
            return current->val_;
        if (index < current->leftChildrenCnt_)
            current = current->left_;
        else {
            index -= (current->leftChildrenCnt_ + 1);
            current = current->right_;
        }
    }
}
