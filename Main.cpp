// TestG5Entertainment.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

#include "CArray.h"

template<class TData>
void printArray(
    CArray<TData>& _myArr
);

void TaskInt1(
    CArray<int>& _myArr
);

void TaskInt2(
    CArray<int>& _myArr
);

void TaskInt3(
    CArray<int>& _myArr
);

void TaskInt4(
    CArray<int>& _myArr
);

void TaskStr5(
    CArray<std::string>& _myArr
);

void TaskStr6(
    CArray<std::string>& _myArr
);

void TaskStr6(
    CArray<std::string>& _myArr
);

void TaskStr7(
    CArray<std::string>& _myArr
);

void TaskStr8(
    CArray<std::string>& _myArr
);

int main()
{
    //TasksInt
    CArray<int> myArr;
    TaskInt1(myArr);
    TaskInt2(myArr);
    TaskInt3(myArr);
    TaskInt4(myArr);

    myArr.clear();

    //TaskString
    CArray<std::string> wordsArr;
    TaskStr5(wordsArr);
    TaskStr6(wordsArr);
    TaskStr7(wordsArr);
    TaskStr8(wordsArr);

    return 0;
}

template<class TData>
void printArray(
    CArray<TData>& _myArr
)
{
    for (unsigned int i = 0; i < _myArr.size(); i++)
    {
        TData data = _myArr[i];
        std::cout << data << std::endl;
    }
}

//TaskInt1
void TaskInt1(
    CArray<int>& _myArr
)
{
    std::cout << std::endl;
    std::cout << "-----TaskInt1-----" << std::endl << std::endl;

    srand(time(NULL));
    for (unsigned int i = 0; i < 20; i++)
    {
        int randomValue = rand() % 100;
        _myArr.push_back(randomValue);
    }

    printArray(_myArr);
}

//TaskInt2
void TaskInt2(
    CArray<int>& _myArr
)
{
    std::cout << std::endl;
    std::cout << "-----TaskInt2-----" << std::endl << std::endl;

    unsigned int minValueIndex = 0;
    int minValue = _myArr[minValueIndex];
    unsigned int lastIndexMinValue = 0;
    unsigned int i = 1;
    bool change = false;

    do
    {
        for (; i < _myArr.size(); i++)
        {
            int currentValue = _myArr[i];
            if (minValue >= currentValue)
            {
                minValue = currentValue;
                minValueIndex = i;
                change = true;
            }
        }

        if (change)
        {
            //swap value
            int bufferValue = _myArr[lastIndexMinValue];
            _myArr[lastIndexMinValue] = minValue;
            _myArr[minValueIndex] = bufferValue;

            lastIndexMinValue++;
            i = lastIndexMinValue;
            minValueIndex = lastIndexMinValue;
            minValue = _myArr[lastIndexMinValue];
            change = false;
        }
    } while (lastIndexMinValue < _myArr.size());

    printArray(_myArr);
}

//TaskInt3
void TaskInt3(
    CArray<int>& _myArr
)
{
    std::cout << std::endl;
    std::cout << "-----TaskInt3-----" << std::endl << std::endl;

    CArray<int> resArray;

    int counterElement = 0;
    for (unsigned int i = 0; i < _myArr.size(); i++)
    {
        counterElement++;
        if (counterElement % 2 == 0)
        {
            int value = _myArr[i - 1];
            resArray.push_back(value);
        }
    }

    _myArr.clear();

    for (unsigned int j = 0; j < resArray.size(); j++)
    {
        int value2 = resArray[j];
        _myArr.push_back(value2);
    }

    printArray(resArray);
}

//TaskInt4
void TaskInt4(
    CArray<int>& _myArr
)
{
    std::cout << std::endl;
    std::cout << "-----TaskInt4-----" << std::endl << std::endl;

    CArray<int> randomValueArr;
    CArray<int> randomIndexArr;

    for (int i = 0; i < 10; i++)
    {
        int randomValue = rand() % 100;
        randomValueArr.push_back(randomValue);
    }

    for (int j = 0; j < 10; j++)
    {
        int range = _myArr.size();
        int randomIndex = rand() % (range - 1);
        randomIndexArr.push_back(randomIndex);
    }

    for (int k = 0; k < 10; k++)
    {
        int index = randomIndexArr[k];
        int value = randomValueArr[k];
        _myArr.insert(index, value);
    }

    printArray(_myArr);
}

//TaskInt5
void TaskStr5(
    CArray<std::string>& _myArr
)
{
    std::cout << std::endl;
    std::cout << "-----TaskInt5-----" << std::endl << std::endl;

    char myWords[25][15] = { "dog", "hello", "international", "ho", "common", "twenty",
                            "centuries", "hihiho", "countryside", "box", "i",
                             "rinori", "shampoo", "tax", "roll", "senator", "congress",
                             "in", "government", "fund", "local", "bill", "tomato",
                             "bottle", "wifi" };

    srand(time(NULL));
    for (int i = 0; i < 15; i++)
    {
        int randomIndex = rand() % 24;
        std::string myWord = std::string(myWords[randomIndex]);
        _myArr.push_back(myWord);
    }

    printArray(_myArr);
}

//TaskInt6
void TaskStr6(
    CArray<std::string>& _myArr
)
{
    std::cout << std::endl;
    std::cout << "-----TaskInt6------" << std::endl << std::endl;

    unsigned int minWordIndex = 0;
    std::string minWord = _myArr[minWordIndex];
    unsigned int lastIndexMinWord = 0;
    unsigned int i = 1;
    bool change = false;

    do
    {
        for (; i < _myArr.size(); i++)
        {
            std::string currentWord = _myArr[i];
            if (minWord.length() >= currentWord.length())
            {
                minWord = currentWord;
                minWordIndex = i;
                change = true;
            }
        }
        if (change)
        {
            //swap value
            std::string bufferWord = _myArr[lastIndexMinWord];
            _myArr[lastIndexMinWord] = minWord;
            _myArr[minWordIndex] = bufferWord;
            change = false;
        }
        lastIndexMinWord++;
        i = lastIndexMinWord;
        minWordIndex = lastIndexMinWord;
        minWord = _myArr[lastIndexMinWord];
    } while (lastIndexMinWord < _myArr.size());

    printArray(_myArr);
}

//TaskInt7
void TaskStr7(
    CArray<std::string>& _myArr
)
{
    std::cout << std::endl;
    std::cout << "-----TaskInt7-----" << std::endl << std::endl;

    CArray<char> letters;

    letters.push_back('a');
    letters.push_back('b');
    letters.push_back('c');
    letters.push_back('d');
    letters.push_back('e');

    CArray<int> indexDelWords;
    bool nextWord = false;

    for (unsigned int i = 0; i < _myArr.size(); i++)
    {
        nextWord = false;
        std::string word = _myArr[i];
        for (unsigned int k = 0; k < word.length(); k++)
        {
            if (!nextWord)
            {
                char letterWord = word[k];
                for (unsigned int j = 0; j < letters.size(); j++)
                {
                    if (!nextWord) {
                        char letter = letters[j];
                        if (letter == letterWord)
                        {
                            indexDelWords.push_back(i);
                            nextWord = true;
                        }
                    }
                }
            }
        }
    }

    CArray<std::string> bufferArray;
    int indexWord = 0;
    bool pushWordInBuffer = true;

    for (unsigned int i = 0; i < _myArr.size(); i++)
    {
        pushWordInBuffer = true;
        for (unsigned int n = 0; n < indexDelWords.size(); n++)
        {
            if (indexWord == indexDelWords[n])
            {
                pushWordInBuffer = false;
            }
        }

        if (pushWordInBuffer)
            bufferArray.push_back(_myArr[indexWord]);

        indexWord++;
    }

    _myArr.clear();

    for (int k = 0; k < bufferArray.size(); k++)
    {
        _myArr.push_back(bufferArray[k]);
    }

    printArray(_myArr);
}

//TaskInt8
void TaskStr8(
    CArray<std::string>& _myArr
)
{
    std::cout << std::endl;
    std::cout << "-----TaskInt8-----" << std::endl << std::endl;

    srand(time(NULL));
    for (unsigned int i = 0; i < 3; i++)
    {
        int r = _myArr.size();
        if (r > 1)
        {
            int randomIndexWord = rand() % (r - 1);
            std::string randomWord = _myArr[randomIndexWord];
            int randomPlaceWord = rand() % (r - 1);
            _myArr.insert(randomPlaceWord, randomWord);
        }
    }

    printArray(_myArr);
}
