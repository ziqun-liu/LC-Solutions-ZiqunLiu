class Trie:

    def __init__(self):
        self.trie = {}

    def insert(self, word: str) -> None:
        hashmap = self.trie

        for c in word:
            if c not in hashmap:
                hashmap[c] = {} # create a new spot
            hashmap = hashmap[c] # moves the current pointer down one level in the Trie

        hashmap['.'] = '.'


    def search(self, word: str) -> bool:
        hashmap = self.trie

        for c in word:
            if c not in hashmap:
                return False
            hashmap = hashmap[c]

        return '.' in hashmap

    def startsWith(self, prefix: str) -> bool:
        """
        If loop through all char's in prefix, all char's exist in the trie
        so return true
        """
        hashmap = self.trie

        for c in prefix:
            if c not in hashmap:
                return False
            hashmap = hashmap[c]

        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)