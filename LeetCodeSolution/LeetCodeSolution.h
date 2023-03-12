#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::cin;
using std::string;

using std::vector;

//Problem
namespace P {

}

//Problem 242, Valid Anagram
namespace P242 {
	class Solution {
	public:
		bool isAnagram(string s, string t) {
			if (s.size() != t.size())
				return false;

			std::unordered_map<char, int> countS, countT;

			for (int i = 0; i < s.size(); i++)
			{
				countS[s[i]] += 1;
				countT[t[i]] += 1;
			}
			for (std::pair<char, int> c : countS) {
				if (countS[c.first] != countT[c.first])
					return false;
			}

			return true;
		}
	};
}

//Problem 1, Two Sum
namespace P1 {
	class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> result;
			std::unordered_map<int, int> prevMap;

			for (int i = 0; i < nums.size(); i++)
			{
				int n = nums[i];
				int diff = target - n;
				if (prevMap.find(diff) != prevMap.end()) {
					result.push_back(prevMap[diff]);
					result.push_back(i);
					return result;
				}
				prevMap[n] = i;
			}

			return result;
		}
	};
}

//Problem 53, Maximum Subarray
namespace P53 {
	// sliding window
	class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			int maxSub = nums[0], curSum = 0;

			for (int n : nums) {
				if (curSum < 0)
					curSum = 0;
				curSum += n;
				maxSub = std::max(maxSub, curSum);
			}

			return maxSub;
		}
	};
}

//Problem 167, Two Sum II - Input Array Is Sorted
namespace P167 {
	class Solution {
	public:
		vector<int> twoSum(vector<int>& numbers, int target) {
			vector<int> result;

			int l = 0, r = numbers.size() - 1;

			while (l < r) {
				int curSum = numbers[l] + numbers[r];

				if (curSum > target)
					r -= 1;
				else if (curSum < target)
					l += 1;
				else {
					result.push_back(l + 1);
					result.push_back(r + 1);
					return result;
				}
			}

			return result;
		}
	};
}

//Problem 198, House Robber
namespace P198 {
	class Solution {
	public:
		int rob(vector<int>& nums) {
			int rob1 = 0, rob2 = 0;

			//[rob1, rob2, n, ...]
			for (int n : nums) {
				int temp = std::max(n + rob1, rob2);
				rob1 = rob2;
				rob2 = temp;
			}

			return rob2;
		}
	};
}

//Problem 21, Merge Two Sorted Lists
namespace P21 {
	//Definition for singly-linked list.
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};

	class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
			ListNode* dummy = new ListNode();
			ListNode* tail = dummy;

			while (list1 != nullptr && list2 != nullptr) {
				if (list1->val < list2->val) {
					tail->next = list1;
					list1 = list1->next;
				}
				else {
					tail->next = list2;
					list2 = list2->next;
				}

				tail = tail->next;
			}

			if (list1 != nullptr) tail->next = list1;
			else if (list2 != nullptr) tail->next = list2;

			return dummy->next;
		}
	};
}

//Problem 121, Best Time to Buy and Sell Stock
namespace P121 {
	class Solution {
	public:
		// Sliding Window
		int maxProfit(vector<int>& prices) {
			int l = 0, r = 1;// left index=buy, right index=sell
			int maxP = 0;

			while (r < prices.size()) {
				// it will make profit
				if (prices[l] < prices[r]) {
					int profit = prices[r] - prices[l];
					maxP = std::max(maxP, profit);
				}
				// else need to find a new l for a lowest buy price
				else {
					l = r;
				}
				r += 1;
			}

			return maxP;
		}
	};
}

//Problem
namespace P {

}