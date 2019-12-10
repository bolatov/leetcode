rom collections import defaultdict
from heapq import heapify, heappop
class Twitter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.timestamp = 0
        self.user_followees = defaultdict(set)
        self.user_tweets = defaultdict(list)

    def postTweet(self, user_id: int, tweet_id: int) -> None:
        """
        Compose a new tweet.
        """
        twit = (self.timestamp, tweet_id)
        self.timestamp += 1
        self.user_tweets[user_id].append(twit)

    def getNewsFeed(self, user_id: int) -> List[int]:
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        """
        feed_limit = 10
        heap = []
        for followee_id in self.user_followees[user_id]:
            tweets = self.user_tweets[followee_id][-feed_limit:]
            heap.extend(tweets)
        own_tweets = self.user_tweets[user_id][-feed_limit:]
        heap.extend(own_tweets)
        heapify(heap)
        while len(heap) > feed_limit:
            heappop(heap)
        twits = []
        while heap:
            _, tweet_id = heappop(heap)
            twits.append(tweet_id)
        return reversed(twits)

    def follow(self, follower_id: int, followee_id: int) -> None:
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        """
        if follower_id != followee_id:
            self.user_followees[follower_id].add(followee_id)

    def unfollow(self, follower_id: int, followee_id: int) -> None:
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        """
        if followee_id in self.user_followees[follower_id]:
            self.user_followees[follower_id].remove(followee_id)


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(user_id,tweet_id)
# param_2 = obj.getNewsFeed(user_id)
# obj.follow(follower_id,followee_id)
# obj.unfollow(follower_id,followee_id)
