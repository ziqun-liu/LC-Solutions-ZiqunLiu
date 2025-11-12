class TrieNode {
	Map<String, TrieNode> children;
	Integer value;

	public TrieNode() {
		this.children = new HashMap<>();
		this.value = null;
	}
}


// TrieNode node = new TrieNode();
// node.val = 14
// node.children.put
// node.children.get()
class FileSystem {
	private static TrieNode root;

	public FileSystem() {
		root = new TrieNode();
	}

	public boolean createPath(String path, int value) {
		// Path DNE
		if (path == null || path.length() == 0)
			return false;

		// [/leetcode/problems] -> ["", "leetcode", "problems"]
		String segments = path.split("/");

		for (int i=1; i<segments.length; i++) {
			String seg = segments[i];

			// node is a pointer
			// Create new path ? 
			if (!node.children.containsKey(arg0)) {
				// parent path DNE, do not create, it is not last one
				if (i < segments.length - 1) { // i is not the last element
					return false;
				} else {
					// Create, it is last one
					node.children.put(seg, arg1);
				}
			} else {
				// Repeater path
				if (i == segments.length - 1)
					return false;
			}

			// Increment pointer
			node = node.children.get(seg);
		}

		node.value = value;
		return true;
	}

	public int get(String path) {
		if (path == null || path.length() == 0)
			return -1;

		String segments = path.split("/");
		TrieNode node = root;

		for (int i=0; i<segments.length; i++) {
			// Path does not contain
			if (!node.children.containsKey(segments[i]))
				return -1;

			node = node.children.get(segments[i]);
		}

		return (node == null) ? -1 : node.value;
	}

}
