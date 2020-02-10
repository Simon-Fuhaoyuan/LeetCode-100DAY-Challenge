#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <tuple>
using namespace std;

void print(vector<int> &news) {
    for (int i = 0; i < news.size(); ++i)
        cout << news[i] << ' ';
    cout << endl;
}

class Twitter {
private:
    unordered_map<int, unordered_set<int>> following_info;
    vector<vector<int>> tweets;
    int tweets_size;
public:
    /** Initialize your data structure here. */
    Twitter() {
        tweets_size = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        vector<int> tmp({userId, tweetId});
        tweets.push_back(tmp);
        tweets_size++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. 
     * Each item in the news feed must be posted by users who the user followed or by the user herself. 
     * Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        bool have_followee = false;
        if (following_info.count(userId) && following_info[userId].size() > 0)
            have_followee = true;
        
        vector<int> news;
        int size = 0;
        for (int i = tweets_size - 1; i >= 0 && size < 10; --i) {
            if (tweets[i][0] == userId) {
                size++;
                news.push_back(tweets[i][1]);
            }
            else if (have_followee && following_info[userId].count(tweets[i][0]) > 0) {
                size++;
                news.push_back(tweets[i][1]);
            }
        }
        return news;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (following_info.count(followerId)) {
            if (!following_info[followerId].count(followeeId))
                following_info[followerId].insert(followeeId);
        }
        else {
            unordered_set<int> tmp;
            tmp.insert(followeeId);
            following_info.insert(make_pair(followerId, tmp));
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (following_info.count(followerId)) {
            if (following_info[followerId].count(followeeId))
                following_info[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

int main() {
    Twitter twitter;
    vector<int> news;

    // User 1 posts a new tweet (id = 5).
    twitter.postTweet(1, 5);

    // User 1's news feed should return a list with 1 tweet id -> [5].
    news = twitter.getNewsFeed(1);
    print(news);

    // User 1 follows user 2.
    twitter.follow(1, 2);

    // User 2 posts a new tweet (id = 6).
    twitter.postTweet(2, 6);

    // User 1's news feed should return a list with 2 tweet ids -> [6, 5].
    // Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
    news = twitter.getNewsFeed(1);
    print(news);

    // User 1 unfollows user 2.
    twitter.unfollow(1, 2);

    // User 1's news feed should return a list with 1 tweet id -> [5],
    // since user 1 is no longer following user 2.
    news = twitter.getNewsFeed(1);
    print(news);

    return 0;
}