#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

class Comparare_map
{
public:
    bool operator() (pair<string, int> a, pair <string, int> b)
    {
        if (a.second == b.second)
            return a.first > b.first;
    
        return a.second < b.second;
    }
};

class Comparare_length
{
public:
    bool operator() (pair<string, int> a, pair <string, int> b)
    {
        if (a.first.length() < b.first.length())
            return true;
        else
            return false;
    }
};

string erase_multiple_space(string word)
{
    int i, n;
    string sep = " ,.?!";
    n = word.length() - 1;

    for (i = 0; i < n; i++)
        if (word[i] >= 'A' && word[i] <= 'Z')
            word[i] = word[i] + 32;

    for (i = 0; i < n; i++)
        if ( sep.find( word[i] ) != string::npos && sep.find( word[i+1] ) != string::npos )
        {
            word.erase(i, 1);
            --i;
        }

    n = word.length() - 1;
    if (sep.find(word[n]) != string::npos)
        word.erase(n, 1);
    
    return word;
}

int main()
{
    string cuvant, token, separatori = " ,?!.";
    map <string, int> words;
    priority_queue< pair<string, int>, vector< pair<string, int> >, Comparare_map > pq;
    priority_queue< pair<string, int>, vector< pair<string, int> >, Comparare_length > pq_length;

    cout << "Introduceti o propozitie: ";
    getline(cin, cuvant);
    unsigned int j;

    cuvant = erase_multiple_space(cuvant);  

    for (j = 0; j < cuvant.length(); ++j)   
    {
        if ( separatori.find( cuvant[j] ) != string::npos )
        {
            token = cuvant.substr(0, j);

            if (words.find(token) != words.end())
                words[token] += 1;
            else
                words.insert({ token,1 });

            cuvant.erase(0, j + 1);
            j = 0;
        }
    }

    if (words.find(cuvant) != words.end())
        words[token] += 1;
    else
        words.insert({ cuvant,1 });


    cout << endl << "Map-ul este: " << endl;
    map<string, int>::iterator it;
    for (it = words.begin(); it != words.end(); it++ )
    {
        cout << it->first << " = " << it->second << endl;
        pq.push({ it->first, it->second });
        pq_length.push({ it->first, it->second });
    }

    cout << endl << "Priority_queue-ul dupa frecventa este: " << endl;
    while ( !pq.empty() )
    {
        cout << pq.top().first << " = " << pq.top().second << "\n";
        pq.pop();
    }


    cout<< endl << "Priority_queue-ul dupa lungime este: " << endl;
    while ( !pq_length.empty())
    { 
        token = pq_length.top().first;
        cout << pq_length.top().first << " are lungimea " << token.length() << "\n";
        pq_length.pop();
    }
    return 0;
}

// I bought an apple. Then I eat an apple. Apple is my favorite.
