import java.util.*;
import java.lang.*;
import java.io.*;


public class Trie{
	
	class TrieNode{
		
		Map <Character,TrieNode> children;
		boolean endofword;

		public TrieNode()
		{
			children=new HashMap<>();
			endofword=false;
		}

	}
	public final TrieNode root;

	public Trie()
	{
		root=new TrieNode();
	}

// insert a string into Trie
	

	public void insert(String word){
		
		int len=word.length();
		TrieNode current = root;
		for(int i=0;i<len;i++)
		{
			TrieNode node = current.children.get(word.charAt(i));
			if(node==null)
			{
				node=new TrieNode();
				current.children.put(word.charAt(i),node);
			}
			current=node;
		}
		current.endofword=true;
	}



	public boolean search(String word){
		
		int len=word.length();
		TrieNode current=root;
		for(int i=0;i<len;i++)
		{
			TrieNode node=current.children.get(word.charAt(i));
			if(node==null)
			{
				return false;
			}
			current=node;
		}
		return current.endofword;
	}

	public boolean delete(TrieNode current,String word,int index){
		

		if(index==word.length())
		{
			if(current.endofword==false)
			{
				return false;
			}
			current.endofword=false;
			return current.children.size()==0;
		}

		TrieNode node=current.children.get(word.charAt(index));
		if(node==null)
			return false;
		
		boolean shouldDelete = delete(node,word,index+1);

		if(shouldDelete)
		{
			current.children.remove(word.charAt(index));
			return current.children.size()==0;
		}
		return false;
	}

	public static void main(String[] args)
	{
		Trie t=new Trie();
		t.insert("surinder");
		t.insert("chaska");
		t.insert("bholi");

		boolean find;
		find=t.search("chaska");
		System.out.println(find);

		find = t.delete(t.root,"chaska",0);
		find=t.search("chaska");
		System.out.println(find);
	}

}