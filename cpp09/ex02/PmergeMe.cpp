#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int const argc, char const *argv[])
{
    this->_isEven = argc % 2 == 0 ? true : false;
    this->_fillArrayVector(argc, argv);
    this->_fillArrayDeque(argc, argv);

    this->_separateArrayDeque(argc);
    this->_separateArrayVector(argc);

    this->_sortPairDescendingDeque();
    this->_sortPairDescendingVector();

    this->_mergeSortDeque(0, this->_mDequePair.size() - 1);
    this->_mergeSortVector(0, this->_m_vectorPair.size() - 1);

    this->_separateMainandSecondArrayDeque();
    this->_separateMainandSecondArrayVector();

    std::vector<std::pair<int, int> >::iterator it = this->_m_vectorPair.begin();
    while (it != this->_m_vectorPair.end())
    {
        std::cout << it->first << " " << it->second << std::endl;
        it++;
    }
}

void PmergeMe::_fillArrayVector(int const argc, char const *argv[])
{
    int valueTemp = 0;

    for (int i = 0; i < argc; i++)
    {
        valueTemp = std::atoi(argv[i]);
        this->_m_vector.push_back(valueTemp);
    }
}

void PmergeMe::_fillArrayDeque(int const argc, char const *argv[])
{
    int valueTemp = 0;

    for (int i = 0; i < argc; i++)
    {
        valueTemp = std::atoi(argv[i]);
        this->_mDeque.push_back(valueTemp);
    }
}

void PmergeMe::_separateArrayDeque(int const argc)
{
    for (int i = 0; i < argc - 1; i += 2)
    {
        this->_mDequePair.push_back(std::make_pair(this->_mDeque.at(i), this->_mDeque.at(i + 1)));
    }
    if (this->_isEven == false && !this->_mDeque.empty())
    {
        this->_lastValue = this->_mDeque.back();
    }
}

void PmergeMe::_separateArrayVector(int const argc)
{
    for (int i = 0; i < argc - 1; i += 2)
    {
        this->_m_vectorPair.push_back(std::make_pair(this->_m_vector.at(i), this->_m_vector.at(i + 1)));
    }
    if (this->_isEven == false && !this->_m_vector.empty())
    {
        this->_lastValue = this->_m_vector.back();
    }
}

void PmergeMe::_sortPairDescendingDeque()
{
    std::deque<std::pair<int, int> >::iterator it;
    for (it = this->_mDequePair.begin(); it != this->_mDequePair.end(); ++it)
    {
        if (it->first < it->second)
        {
            std::swap(it->first, it->second);
        }
        ++it;
    }
}

void PmergeMe::_sortPairDescendingVector()
{
    std::vector<std::pair<int, int> >::iterator it;
    for (it = this->_m_vectorPair.begin(); it != this->_m_vectorPair.end(); ++it)
    {
        if (it->first < it->second)
        {
            std::swap(it->first, it->second);
        }
    }
}

void PmergeMe::_mergeDeque(std::deque<std::pair<int, int> > &mDeque, int begin, int middle, int end)
{
    std::deque<std::pair<int, int> > left(middle - begin + 1);
    std::deque<std::pair<int, int> > right(end - middle);

    std::copy(mDeque.begin() + begin, mDeque.begin() + middle + 1, left.begin());
    std::copy(mDeque.begin() + middle + 1, mDeque.begin() + end + 1, right.begin());

    size_t topLeft = 0;
    size_t topRight = 0;
    size_t topMerge = begin;

    while (topLeft < left.size() && topRight < right.size())
    {
        if (left.at(topLeft).first <= right.at(topRight).first)
        {
            mDeque.at(topMerge) = left.at(topLeft);
            topLeft++;
        }
        else
        {
            mDeque.at(topMerge) = right.at(topRight);
            topRight++;
        }
        topMerge++;
    }

    while (topLeft < left.size())
    {
        mDeque.at(topMerge) = left.at(topLeft);
        topLeft++;
        topMerge++;
    }

    while (topRight < right.size())
    {
        mDeque.at(topMerge) = right.at(topRight);
        topRight++;
        topMerge++;
    }
}

void PmergeMe::_mergeSortDeque(int begin, int end)
{
    if (begin < end)
    {
        int middle = (begin + end) / 2;
        this->_mergeSortDeque(begin, middle);
        this->_mergeSortDeque(middle + 1, end);
        this->_mergeDeque(this->_mDequePair, begin, middle, end);
    }
}

void PmergeMe::_mergeVector(std::vector<std::pair<int, int> > &m_vector, int begin, int middle, int end)
{
    std::vector<std::pair<int, int> > left(middle - begin + 1);
    std::vector<std::pair<int, int> > right(end - middle);

    std::copy(m_vector.begin() + begin, m_vector.begin() + middle + 1, left.begin());
    std::copy(m_vector.begin() + middle + 1, m_vector.begin() + end + 1, right.begin());

    size_t topLeft = 0;
    size_t topRight = 0;
    size_t topMerge = begin;

    while (topLeft < left.size() && topRight < right.size())
    {
        if (left.at(topLeft).first <= right.at(topRight).first)
        {
            m_vector.at(topMerge) = left.at(topLeft);
            topLeft++;
        }
        else
        {
            m_vector.at(topMerge) = right.at(topRight);
            topRight++;
        }
        topMerge++;
    }

    while (topLeft < left.size())
    {
        m_vector.at(topMerge) = left.at(topLeft);
        topLeft++;
        topMerge++;
    }

    while (topRight < right.size())
    {
        m_vector.at(topMerge) = right.at(topRight);
        topRight++;
        topMerge++;
    }
}

void PmergeMe::_mergeSortVector(int begin, int end)
{
    if (begin < end)
    {
        int middle = (begin + end) / 2;
        this->_mergeSortVector(begin, middle);
        this->_mergeSortVector(middle + 1, end);
        this->_mergeVector(this->_m_vectorPair, begin, middle, end);
    }
}

void PmergeMe::_separateMainandSecondArrayDeque()
{
    this->_mainArrayDeque.push_back(this->_mDequePair.at(0).first);
    for (size_t i = 0; i < this->_mDequePair.size(); i++)
    {
        this->_mainArrayDeque.push_back(this->_mDequePair.at(i).first);
        this->_secondArrayDeque.push_back(this->_mDequePair.at(i).second);
    }
}

void PmergeMe::_separateMainandSecondArrayVector()
{
    this->_mainArrayVector.push_back(this->_m_vectorPair.at(0).first);
    for (size_t i = 0; i < this->_m_vectorPair.size(); i++)
    {
        this->_mainArrayVector.push_back(this->_m_vectorPair.at(i).first);
        this->_secondArrayVector.push_back(this->_m_vectorPair.at(i).second);
    }
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    (void)src;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
    if (this != &rhs)
    {
    }
    return *this;
}
