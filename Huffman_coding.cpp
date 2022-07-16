#include "CpHEADERFILE.h"
#include "Node.h"

// function for new tree
Node *getNode(char c, int freq, Node *left, Node *right)
{
    Node *t = new Node();
    t->c = c;
    t->freq = freq;
    t->left = left;
    t->right = right;
    return t;
}

// in this we maintaining heap order property highest prirority is on top
struct comp
{
    bool operator()(Node *left, Node *right)
    {
        return left->freq > right->freq;
    }
};
// Encode function
// We traversing the huffman and storing code in map correspondence to char
void encode(Node *root, string str, map<char, string> &huffmanCode)
{
    // base case
    if (!root)
        return;
    if (!root->left && !root->right)
        huffmanCode[root->c] = str;

    // in left we are assingning 0 so making recursive call on left by adding 0
    encode(root->left, str + "0", huffmanCode);
    // in right we are assingning 1 so making recursive call on right by adding 1 to string code
    encode(root->right, str + "1", huffmanCode);
}

// Decode Function
//  Traversing huffmanTree and decode the string
void decode(Node *root, int &ind, string str)
{
    // base case
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        cout << root->c;
        return;
    }
    ind++;
    if (str[ind] == '0')
        decode(root->left, ind, str);
    else
        decode(root->right, ind, str);
}

// WorkFlow
// Building the huffman Tree
// 1.counting and storing the frequency of each character in map
// 2.Creating tree node leaf corresponding to freq data
// 3.Creating tree
// 1.remove the two top priority elemnt ie lowest freq(count of char)
// 2.push the node equal to sum of freq of both children.
// 4.Traversing the whole huffman tree and store huffman codes in map as like for g 0001
// 5.Printing the decoded string and original also compression ration
void buildHuffman(string text)
{
    // 1.
    map<char, int> freq;
    for (auto c : text)
    {
        freq[c]++;
    }

    priority_queue<Node *, vector<Node *>, comp> tree;
    // 2.Creating leaf node of each character stored in the map and insert in root;
    for (auto itr : freq)
    {
        tree.push(getNode(itr.ff, itr.ss, NULL, NULL));
    }

    // 3.Creating tree
    // 1.remove the two top priority elemnt ie lowest freq(count of char)
    // 2.push the node equal to sum of freq of both children
    while (tree.size() != 1)
    {
        // 1.
        Node *left = tree.top();
        tree.pop();
        Node *right = tree.top();
        tree.pop();
        // 2.
        int sum = left->freq + right->freq;
        tree.push(getNode(NULL, sum, left, right));
    }

    // Root of huffman Tree we build
    Node *root = tree.top();
    cout << "Huffman Tree Is Created" << endl;
    /// Traversing the whole huffman tree and store huffman codes in map
    map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    // Original String printing
    cout << "Original string was: \n"
         << text << endl;
    cout << endl;

    // printing encoded string
    string res = "";
    for (char c : text)
        res += huffmanCode[c];
    /// Printing huffman coded string for the given text;
    cout << "Encoded string is: \n"
         << res << endl;

    // Compression ratio
    int org = 7 * text.length();
    int conv = ceil(res.length() / 8);
    double compressionRate = (double)conv / org;
    cout << "String is compressed to " << compressionRate * 100 << "% of the total size." << endl;

    cout << "HUFFMAN CODES ARE: \n"
         << endl;

    /// Printing codes for each character
    for (auto itr : huffmanCode)
    {
        cout << itr.ff << " : " << itr.ss << endl;
    }
    cout << endl;

    /// Traversing the huffman tree again so as to decode the string res
    int index = -1;
    cout << "\nDecoded string is: \n";
    while (index < res.size() - 2)
    {
        decode(root, index, res);
    }
    cout << text << endl;
    cout << endl
         << endl;
}

signed main()
{
    fastIO
        string str;
    getline(cin, str);

    buildHuffman(str);

    return 0;
}