class LRUCache {
  public:
    list < pair < int, int > > cache;
  list < pair < int, int > > ::iterator cacheIt;
  unordered_map < int, list < pair < int, int > > ::iterator > keyPosition;

  int cacheSize;

  LRUCache(int capacity) {
    cacheSize = capacity;
  }

  int get(int key) {

    int value = -1;

    if (cacheSize == 0) {
      return -1;
    }

    if (keyPosition.find(key) != keyPosition.end()) {

      cacheIt = keyPosition[key];
      value = cacheIt -> second;

      //delete current position and insert it in front
      cache.erase(cacheIt);
      cache.push_front(make_pair(key, value));

      //update keyPosition
      keyPosition[key] = cache.begin();
    }

    return value;

  }

  void put(int key, int value) {

    if (cacheSize == 0) {
      return;
    }

    if (keyPosition.find(key) == keyPosition.end()) {

      if (cacheSize == cache.size()) {

        cacheIt = --cache.end();
        int lastKeyInCache = cacheIt -> first;

        cache.erase(cacheIt);
        keyPosition.erase(lastKeyInCache);
      }

    } else {
      cache.erase(keyPosition[key]);
      // keyPosition.erase(key); not required as in end we are updating it
    }

    cache.push_front(make_pair(key, value));
    keyPosition[key] = cache.begin();

  }
};
