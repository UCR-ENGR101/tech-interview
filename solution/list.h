#include <initializer_list>
#include <iostream>

namespace engr101 {
    template <class T> class list {
        protected:
        class node {
            public:
            node(const T &t, node *f = nullptr, node *b = nullptr): data(t), forward(f), backward(b) {}
            T data;
            node *forward;
            node *backward;
        };

        private:
        node *head;
        node *tail;

        public:
        list(): head(nullptr), tail(nullptr) {}
        list(std::initializer_list<T> l) : head(nullptr), tail(nullptr) {
            for(auto i = l.begin(); i != l.end(); ++i) {
                push_back(*i);
            }            
        }

        public:
        class iterator {
            using value_type = T;
            using pointer = T*;
            using reference = T&;

            node *n;
            public:
            iterator(node *n): n(n) {}
            iterator &operator++() { n = n->forward; return *this; }
            iterator operator++(int) { iterator temp = *this; n = n->forward; return temp; }

            bool operator==(const iterator &b) { return n == b.n; }
            bool operator!=(const iterator &b) { return n != b.n; }

            reference operator*() { return n->data; }
        };

        void push_back(const T &t) {
            if (head == nullptr && tail == nullptr) {
                head = tail = new node(t, nullptr, nullptr);
            } else {
                tail = tail->forward = new node(t, nullptr, tail);
            }        
        }

        void reverse() {
            for (auto curr = head; curr != nullptr; curr = curr->backward) {
                std::swap(curr->forward, curr->backward);
            }
            std::swap(head, tail);
        }

        iterator begin() { return iterator(head); }
        iterator end() { return iterator(nullptr); }
    };

    template <class T> class forward_list {
        protected:
        class node {
            public:
            node(const T& t, node *f = nullptr): data(t), forward(f) {}
            T data;
            node *forward;
        };

        private:
        node *head;
        node *tail;

        public:
        forward_list(): head(nullptr), tail(nullptr) {}
        forward_list(std::initializer_list<T> l): head(nullptr), tail(nullptr) {
            for (auto i = l.begin(); i != l.end(); ++i) {
                push_back(*i);
            }
        }

        public:
        class iterator {
            using value_type = T;
            using pointer = T*;
            using reference = T&;

            node *n;
            public:
            iterator(node *n): n(n) {}
            iterator &operator++() { n = n->forward; return *this; }
            iterator operator++(int) { iterator temp = *this; n = n->forward; return temp; }

            bool operator==(const iterator &b) { return n == b.n; }
            bool operator!=(const iterator &b) { return n != b.n; }

            reference operator*() { return n->data; }
        };

        public:
        void push_back(const T &t) {
            if (head == nullptr && tail == nullptr) {
                head = tail = new node(t, nullptr);
            } else {
                tail = tail->forward = new node(t, nullptr);
            }
        }

        void reverse() {
            if (head == nullptr && tail == nullptr) return;

            for (node *prev = nullptr, *curr = head, *next = head->forward; curr != nullptr;) {
                curr->forward = prev;
                prev = curr;
                curr = next;
                if (next != nullptr) next = next->forward;
            }
            std::swap(head, tail);
        }

        iterator begin() { return iterator(head); }
        iterator end() { return iterator(nullptr); }
    };
}


