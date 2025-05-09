class Solution {
public:
    bool canFinish(int numCourses, const vector<vector<int>>& prerequisites) {
        for (const auto req : prerequisites) {
            reqs.emplace(req.front(), req.back());
        }
        ok = new bool[numCourses]{};

        for (int i = 0; i < numCourses; ++i) {
            unordered_set<int> seen;
            if (!canFinish(i, seen))
                return false;
        }
        return true;
    }

    bool canFinish(int i, unordered_set<int>& seen) {
        if (ok[i])
            return true;
        if (seen.contains(i))
            return false;
        seen.insert(i);

        for (auto [it, end] = reqs.equal_range(i); it != end; ++it) {
            if (!canFinish(it->second, seen))
                return false;
        }
        ok[i] = true;
        return true;
    }

private:
    unordered_multimap<int, int> reqs;
    bool* ok;
};