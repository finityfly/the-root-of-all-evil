import heapq
from collections import defaultdict
from typing import List

class Twitter:

    def __init__(self):
        self.time = 0
        self.tweet = defaultdict(list) # userID -> (time, tweetID)
        self.follows = defaultdict(set) # userID -> (followeeID)
        

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweet[userId].append((self.time, tweetId))
        self.time += 1
        

    def getNewsFeed(self, userId: int) -> list[int]:
        res = []
        h = []
        userList = list(self.follows[userId]) + [userId]
        for user in userList:
            for userTweet in self.tweet[user][-10:]:
                heapq.heappush(h, (-userTweet[0], userTweet[1]))
        while h and len(res) < 10:
            res.append(heapq.heappop(h)[1])
        return res
        

    def follow(self, followerId: int, followeeId: int) -> None:
        self.follows[followerId].add(followeeId)

    def unfollow(self, followerId: int, followeeId: int) -> None:
        self.follows[followerId].discard(followeeId)
        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)