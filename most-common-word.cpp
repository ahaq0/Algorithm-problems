/*
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.  Words in the paragraph are not case sensitive.  The answer is in lowercase.



*/

// First solution, so one took me a bit to come up with and as expected was pretty slow
// 12ms faster than 15% and 10.8 mb less than 8%. I used both a set and  a hashtable then it can be solved with just one. Similarly the process of getting the max separately from when I add them slows me down 



class Solution {
public:
    
    
    
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        
        // fill in the vector with every word parsed out
        
        
        

        // make a set of all of the banned words due to the O(1) search
        
                unordered_set<string> bans(banned.begin(), banned.end());

        // map every non banned word to it's count
        unordered_map<string,int> wordCount;
         
        // quick method to remove everything but characters from the input paragraph
        for ( auto & c : paragraph)
        {
            c = isalpha(c) ? tolower(c) : ' ';
        }
        
        
        std::stringstream ss(paragraph);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
         vector<string> strs(begin, end);
        std::copy(strs.begin(), strs.end(), std::ostream_iterator<std::string>(std::cout, "\n"));

        pair<string, int> res ("", 0);

        
        // iterate through all words
        for ( const auto & i : strs)
        {
            // If we find it
            if(bans.find(i) == bans.end())
           {
               // increment the count
                cout << i << "  ";
                wordCount[i]++;
           }
        }
               
       int max = 0;
       string word = "";
       for ( auto  x : wordCount)
       {
           
           //cout << x.first<< " " << x.second << "\n";
          
            
           if(max == 0)
           {
               word = x.first;
            max = x.second;
           }
           if(x.second > max)
           {
            word = x.first;
            max = x.second;
           }
       }
               
               return word;
    
    }
               
              
};

 

 // A better solutions;  92% less memory as just the set and map are used ( no extranerous arrays for storing the paragraph)
 // similarly it's faster since once we move through the input once not 
 class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        unordered_set<string> ban(banned.begin(), banned.end());
        unordered_map<string, int> count;
        // minimal way to strip input
        for (auto & c: paragraph) c = isalpha(c) ? tolower(c) : ' ';
        istringstream input(paragraph);
        string w;
        pair<string, int> defaults ("", 0);
        while (input >> w)
            if (ban.find(w) == ban.end() && ++count[w] > defaults.second)
                defaults = make_pair(w, count[w]);
        return defaults.first;

        
    }
};