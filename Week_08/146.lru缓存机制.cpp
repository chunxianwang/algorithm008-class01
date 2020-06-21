/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

/*
LRU缓存操作原理：
头部放最新访问数据，尾部放很久前访问的数据；
1.访问数据，查询待访问数据地址，若有，返回此地址中存储的值，并把它放入头部；
2.存入数据，查询待访问数据地址，若有，把它调整到头部；若无，把它插入到头部，并判断cache是否溢出（超过其capacity），若溢出，删掉尾部；

LRU的get，put操作的两个关键元素：key 和 value， 理解成cache的地址索引和其中存储的值；
note，为区别哈希列表和cache，在下述哈希列表中，用键和值表述hash_map的key和value；
双端链表，cache的数据存储。 key，对应于cache的key，就是cache的地址索引；value，对应于cache的value，实际存放的数据；
哈希列表，键，对应于cache的key，就是cache的地址索引； 值，对应于链表的结点的地址；

为什么不用单链表？
单链表，只定义了head，如果想要快速访问tail，要逐个从头部到尾部遍历，时间复杂度O(n)；不适用于用O(1)访问和删除尾部的场景；
而双链表，定义了head和tail，访问和删除尾部时，就比较迅速了;
*/
// @lc code=start
#include<unordered_map>
using namespace std;
//双端链表，具体的cache实现结构
struct DlinkNode {     
    int key, value;
    DlinkNode* prev;
    DlinkNode* next;
    DlinkNode() : key(0), value(0), prev(nullptr), next(nullptr) {}   //构造，无参数，初始化
    DlinkNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {} //构造，有参数，初始化
};

class LRUCache {
private:
    unordered_map<int, DlinkNode*> cache;   //哈希map 存放索引cache的信息
    DlinkNode* head;
    DlinkNode* tail;
    int size;
    int capacity;
public:
    LRUCache(int _capacity): capacity(_capacity), size(0) {
        head = new DlinkNode();
        tail = new DlinkNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        DlinkNode* node = cache[key];
        moveToHead(node);
        return node->value;   //获取cache数据，链表中的值；

    }
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            DlinkNode* node = new DlinkNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity) {
                DlinkNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }
        else {
            DlinkNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
    void addToHead(DlinkNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    void removeNode(DlinkNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void  moveToHead(DlinkNode* node) {
        removeNode(node);
        addToHead(node);
    }
    DlinkNode* removeTail() {
        DlinkNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

