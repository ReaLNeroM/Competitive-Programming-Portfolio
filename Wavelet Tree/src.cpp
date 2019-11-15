#include <bits/stdc++.h>

typedef long long ll;

struct Wavelet_Tree {
	struct Node {
		std::vector<char> alphabet;
		std::string content;
	};

	Node treeNodes[2 * N];

	init(std::string s){
		std::set<char> alphabetSet;
		for(char i : s){
			alphabetSet.insert(i);
		}
		std::vector<char> alphabet;
		for(auto ite = alphabetSet.begin(); ite != alphabetSet.end(); ++ite){
			alphabet.push_back(*ite);
		}

		treeNodes[0].alphabet = alphabet;
		treeNodes[0].content = s;
		build();
	}

	void build(int ind = 0){
		Node* currNode = &treeNodes[ind];

		if(currNode->alphabet.size() == 1){
			return;
		}

		Node* leftNode = &treeNodes[2 * ind + 1];
		Node* rightNode = &treeNodes[2 * ind + 2];

		int mid = currNode->alphabet.size() / 2;

		std::unordered_set<char> leftAlphabet;
		for(int i = 0; i < currNode->alphabet.size(); i++){
			if(i < mid){
				leftAlphabet.insert(currNode->alphabet[i]);
				leftNode->alphabet.push_back(currNode->alphabet[i]);
			} else {
				rightNode->alphabet.push_back(currNode->alphabet[i]);
			}
		}

		for(char i : treeNodes[ind].content){
			if(leftAlphabet.count(i)){
				leftNode->content += i;
			} else {
				rightNode->content += i;
			}
		}

		build(2 * ind + 1);
		build(2 * ind + 2);
	}
};

int main(){
	std::string s;
	s = "abracadabra";
	// std::cin >> s;

	int n = s.size();

	Wavelet_Tree tree(s);
}