class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # groups = {}
        # for word in strs:
        #     key = "".join(sorted(word))
        #     if key not in groups:
        #         groups[key] = []
        #     groups[key].append(word)
        # return list(groups.values())

        res = defaultdict(list)

        for s in strs:
            count = [0] * 26

            for c in s:
                count[ord(c) - ord("a")] += 1
            res[tuple(count)].append(s)
        return list(res.values())