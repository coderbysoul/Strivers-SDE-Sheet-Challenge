//https://www.codingninjas.com/codestudio/problems/sort-a-stack_8230787?challengeSlug=striver-sde-challenge

#include <bits/stdc++.h> 

void insert(int a, stack<int>& stack)
{
	if (stack.size() == 0 || stack.top() < a)
	{
		stack.push(a);
	}
	else
	{
		int x = stack.top();
		stack.pop();
		insert(a, stack);
		stack.push(x);
	}
}

void reverse(stack<int>& stack)
{
	if (stack.size() > 0)
	{
		int a = stack.top();
		stack.pop();
		reverse(stack);
		insert(a, stack);
	}
}

void sortStack(stack<int>& stack)
{
	reverse(stack);
}
