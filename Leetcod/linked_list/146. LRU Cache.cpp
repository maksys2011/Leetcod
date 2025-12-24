#include <list>
#include <unordered_map>

class LRUCache
{
private:
  int capacity_;
  std::list<std::pair<int, int>> items;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache;

public:
  LRUCache(int capacity) : capacity_(capacity){}
  
  int get(int key)
  {
    auto it = cache.find(key);
    if(it == cache.end()) return -1;
    
    items.splice(items.begin(), items, it->second);
    
    return it->second->second;
  }
  
  void put(int key, int value){
    auto it = cache.find(key);
    if(it != cache.end()){
      it->second->second = value;
      items.splice(items.begin(), items, it->second);
      return;
    }
    
    if(items.size() == capacity_){
      int lastkey = items.back().first;
      cache.erase(lastkey);
      items.pop_back();
    }
    items.push_front({key, value});
    cache[key] = items.begin();
  }
};

