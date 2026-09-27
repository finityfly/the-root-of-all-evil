class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.contains(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int steps = 1;

        // word based bfs
        while (!q.empty()) {
            int levelSize = q.size();
            for (int k = 0; k < levelSize; ++k) {
                string word = q.front(); q.pop();
                if (word == endWord) return steps;
                for (int i = 0; i < (int)word.size(); ++i) {
                    char orig = word[i];
                    for (int j = 0; j < 26; ++j) {
                        word[i] = (char)('a'+j);
                        if (words.contains(word)) {
                            q.push(word);
                            words.erase(word);
                        }
                    }
                    word[i] = orig;
                }
            }
            ++steps;
        }
        return 0;
    }
};