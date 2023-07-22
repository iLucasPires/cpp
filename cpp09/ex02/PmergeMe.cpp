#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int const argc, char const *argv[])
{
    this->_isEven = argc % 2 == 0 ? true : false;
    this->_fillArrayVector(argc, argv);
    this->_fillArrayDeque(argc, argv);

    this->_separateArrayDeque(argc);
    this->_separateArrayVector(argc);

    this->_sortPairDescendingDeque();
    // this->_sortPairDescendingVector();

    this->_mergeSortDeque(0, this->_mDequePair.size() - 1);
    // this->_mergeSortVector(0, this->_mVectorPair.size() - 1);

    std::cout << "====================== AFTER MERGE SORT ======================" << std::endl;
    for (size_t i = 0; i < this->_mDequePair.size(); i++)
    {
        std::cout << this->_mDequePair.at(i).first << " " << this->_mDequePair.at(i).second << std::endl;
    }
    this->_fillMainAndSecondArrayDeque();
    // this->_fillMainAndSecondArrayVector();

    this->_fillSequenceJacobsthalDeque();
    this->_gerenatePositionsDeque();
    this->_orderArrayDeque();

    std::cout << "====================== AFTER ORDER ======================" << std::endl;
    for (size_t i = 0; i < this->_mainArrayDeque.size(); i++)
    {
        std::cout << this->_mainArrayDeque.at(i) << " - ";
    }
    std::cout << std::endl;
}

int generationSequenceJacobsthal(int const n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    return generationSequenceJacobsthal(n - 1) + 2 * generationSequenceJacobsthal(n - 2);
}

int binarySearch(std::deque<int>  array, int target, int begin, int end)
{
	int mid;

	while (begin <= end)
	{
		mid = begin + (end - begin) / 2;
		if (target == array.at(mid))
			return (mid);

		if (target > array.at(mid))
			begin = mid + 1;
		else
			end = mid - 1;
	}
	if (target > array.at(mid))
		return (mid + 1);
	else
		return (mid);
}


/* #region vectors */
void PmergeMe::_fillArrayVector(int const argc, char const *argv[])
{
    int valueTemp = 0;

    for (int i = 0; i < argc; i++)
    {
        valueTemp = std::atoi(argv[i]);
        this->_mVector.push_back(valueTemp);
    }
}

void PmergeMe::_separateArrayVector(int const argc)
{
    for (int i = 0; i < argc - 1; i += 2)
    {
        this->_mVectorPair.push_back(std::make_pair(this->_mVector.at(i), this->_mVector.at(i + 1)));
    }
    if (this->_isEven == false && !this->_mVector.empty())
    {
        this->_lastValue = this->_mVector.back();
    }
}

void PmergeMe::_sortPairDescendingVector()
{
    std::vector<std::pair<int, int> >::iterator it;
    for (it = this->_mVectorPair.begin(); it != this->_mVectorPair.end(); ++it)
    {
        if (it->first < it->second)
        {
            std::swap(it->first, it->second);
        }
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

void PmergeMe::_fillMainAndSecondArrayVector()
{
    this->_mainArrayVector.push_back(this->_mVectorPair.at(0).second);
    for (size_t i = 0; i < this->_mVectorPair.size(); i++)
    {
        this->_mainArrayVector.push_back(this->_mVectorPair.at(i).first);
        this->_secondArrayVector.push_back(this->_mVectorPair.at(i).second);
    }
}

/* #endregion */

/* #region deques */
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
    std::cout << "====================== BEFORE SORT ======================" << std::endl;
    std::deque<std::pair<int, int> >::iterator it;
    for (it = this->_mDequePair.begin(); it != this->_mDequePair.end(); ++it)
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void PmergeMe::_sortPairDescendingDeque()
{
    int size = this->_mDequePair.size();
    for (int i = 0; i < size; i++)
    {
        if (this->_mDequePair.at(i).first < this->_mDequePair.at(i).second)
        {
            std::swap(this->_mDequePair.at(i).first, this->_mDequePair.at(i).second);
        }
    }

    std::cout << "====================== AFTER SORT ======================" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << this->_mDequePair.at(i).first << " " << this->_mDequePair.at(i).second << std::endl;
    }
}

void PmergeMe::_mergeSortVector(int begin, int end)
{
    if (begin < end)
    {
        int middle = (begin + end) / 2;
        this->_mergeSortVector(begin, middle);
        this->_mergeSortVector(middle + 1, end);
        this->_mergeVector(this->_mVectorPair, begin, middle, end);
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

void PmergeMe::_fillMainAndSecondArrayDeque()
{
    size_t i = 0;
    while (i < this->_mDequePair.size())
    {
        this->_mainArrayDeque.push_back(this->_mDequePair.at(i).first);
        this->_secondArrayDeque.push_back(this->_mDequePair.at(i).second);
        i++;
    }
}


void PmergeMe::_fillSequenceJacobsthalDeque()
{
   	size_t size;
	size_t jcobstalIndex;
	int index;

	size = this->_secondArrayDeque.size();
	index = 3;

	while ((jcobstalIndex = generationSequenceJacobsthal(index)) < size - 1)
	{
		this->_sequenceJacobsthalDeque.push_back(jcobstalIndex);
		index++;
	}
}

void PmergeMe::_gerenatePositionsDeque()
{
  	size_t val;
	size_t pos;
	size_t lastPos;
	size_t i;

	if (this->_secondArrayDeque.empty())
		return;
	lastPos = 1;
	val = 1;
	i = 0;
	while (i < this->_sequenceJacobsthalDeque.size())
	{
		val = this->_sequenceJacobsthalDeque.at(i);

		this->_positionsDeque.push_back(val);

		pos = val - 1;
		while (pos > lastPos)
		{
			this->_positionsDeque.push_back(pos);
			pos--;
		}
		lastPos = val;
		i++;
	}
	while (val++ < this->_secondArrayDeque.size())
		this->_positionsDeque.push_back(val);
}

void PmergeMe::_orderArrayDeque()
{
    std::deque<int>::iterator it;
	int target;
	size_t endPos;
	size_t addedCount = 0;
	size_t pos;

    for (it = this->_positionsDeque.begin(); it != this->_positionsDeque.end();it++)
    {
       target = this->_secondArrayDeque.at(*it - 1);

        endPos = *it + addedCount;
        pos = binarySearch(this->_mainArrayDeque, target, 0, endPos);
        this->_mainArrayDeque.insert(this->_mainArrayDeque.begin() + pos, target);
        addedCount++;
    }
    if (this->_isEven == false)
    {
        pos = binarySearch(this->_mainArrayDeque, this->_lastValue, 0, this->_mainArrayDeque.size() - 1);
        this->_mainArrayDeque.insert(this->_mainArrayDeque.begin() + pos, this->_lastValue);
    }
}


/* #endregion */

/* #region rule 03 */
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
/* #endregion */
