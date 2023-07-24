#include "PmergeMe.hpp"
#include <iomanip>
#include <set>

void PmergeMe::printTime()
{
    double elapsedDeque = static_cast<double>(this->_tempDeque) / CLOCKS_PER_SEC * MICROSECONDS;
    double elapsedVector = static_cast<double>(this->_tempVector) / CLOCKS_PER_SEC * MICROSECONDS;


    std::cout << "Execution time with [vector]: " << std::fixed << std::setprecision(10) << elapsedDeque << " seconds" << std::endl;
    std::cout << "Execution time with [deque]:  " << std::fixed << std::setprecision(10) << elapsedVector << " seconds" << std::endl;

}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int const argc, char const *argv[])
{
    this->ford_johnson_with_vector(argc, argv);
    this->ford_johnson_with_deque(argc, argv);

    this->printBeforeAndAfterVector();
    this->printBeforeAndAfterDeque();


    this->printTime();
}

void PmergeMe::printBeforeAndAfterDeque()
{
    std::cout << "Before order with [deque]: ";
    for (size_t i = 0; i < this->_mDeque.size(); i++)
    {
        std::cout << this->_mDeque[i] << " ";
    }

    std::cout << "\nAfter order with [deque]:  ";
    for (size_t i = 0; i < this->_mainArrayDeque.size(); i++)
    {
        std::cout << this->_mainArrayDeque[i] << " ";
    }

    std::cout << "\n\n==================================================\n\n";
}

void PmergeMe::printBeforeAndAfterVector()
{
    std::cout << "Before order with [vector]: ";
    for (size_t i = 0; i < this->_mVector.size(); i++)
    {
        std::cout << this->_mVector[i] << " ";
    }

    std::cout << "\nAfter order with [vector]:  ";
    for (size_t i = 0; i < this->_mainArrayVector.size(); i++)
    {
        std::cout << this->_mainArrayVector[i] << " ";
    }

    std::cout << "\n\n==================================================\n\n";
}

void PmergeMe::ford_johnson_with_vector(int const argc, char const *argv[])
{
    clock_t start, end;

    start = clock();
    this->_isEven = argc % 2 == 0 ? true : false;
    this->_fillArrayVector(argc, argv);
    this->_separateArrayVector(argc);
    this->_sortPairDescendingVector();
    this->_mergeSortVector(0, this->_mVectorPair.size() - 1);
    this->_fillMainAndSecondArrayVector();
    this->_fillSequenceJacobsthalVector();
    this->_gerenatePositionsVector();
    this->_orderArrayVector();
    end = clock();
    this->_tempDeque = end - start;
}

void PmergeMe::ford_johnson_with_deque(int const argc, char const *argv[])
{
    clock_t start, end;

    start = clock();
    this->_isEven = argc % 2 == 0 ? true : false;
    this->_fillArrayDeque(argc, argv);
    this->_separateArrayDeque(argc);
    this->_sortPairDescendingDeque();
    this->_mergeSortDeque(0, this->_mDequePair.size() - 1);
    this->_fillMainAndSecondArrayDeque();
    this->_fillSequenceJacobsthalDeque();
    this->_gerenatePositionsDeque();
    this->_orderArrayDeque();
    end = clock();
    this->_tempVector = end - start;
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
        if (i + 1 < argc)
        {
            this->_mDequePair.push_back(std::make_pair(this->_mDeque[i], this->_mDeque[i + 1]));
        }
    }
    if (!this->_isEven && !this->_mDeque.empty())
    {
        this->_lastValue = this->_mDeque.back();
    }
}

void PmergeMe::_sortPairDescendingDeque()
{
    for (size_t i = 0; i < this->_mDequePair.size(); i++)
    {
        if (this->_mDequePair.at(i).first < this->_mDequePair.at(i).second)
        {
            std::swap(this->_mDequePair.at(i).first, this->_mDequePair.at(i).second);
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

void PmergeMe::_fillMainAndSecondArrayDeque()
{
    size_t i = 0;

    this->_mainArrayDeque.push_back(this->_mDequePair.at(i).second);
    while (i < this->_mDequePair.size())
    {
        this->_mainArrayDeque.push_back(this->_mDequePair.at(i).first);
        this->_secondArrayDeque.push_back(this->_mDequePair.at(i).second);
        i++;
    }
}

void PmergeMe::_fillSequenceJacobsthalDeque()
{
	int index = 3;
	size_t jcobstalIndex;
   	size_t size = this->_secondArrayDeque.size();

	while ((jcobstalIndex = generationSequenceJacobsthal(index)) < size - 1)
	{
		this->_sequenceJacobsthalDeque.push_back(jcobstalIndex);
		index++;
	}
}

void PmergeMe::_gerenatePositionsDeque()
{
  	size_t jacobsIndex = 1;
	size_t lastPos = 1;

    for (size_t i = 0; i < this->_sequenceJacobsthalDeque.size(); ++i)
    {
        jacobsIndex  = this->_sequenceJacobsthalDeque.at(i);
        this->_positionsDeque.push_back(jacobsIndex );
        for (size_t pos = jacobsIndex - 1; pos > lastPos; --pos)
        {
            this->_positionsDeque.push_back(pos);
        }
        lastPos = jacobsIndex ;
	}
    for (size_t i = jacobsIndex; i  < this->_secondArrayDeque.size(); ++i)
    {
        this->_positionsDeque.push_back(i + 1);
    }
}

void PmergeMe::_orderArrayDeque()
{
    size_t addedCount = 0;
    std::deque<int>::iterator insertPosition;
    for (size_t i = 0; i < this->_positionsDeque.size(); i++)
    {
        insertPosition = std::lower_bound(this->_mainArrayDeque.begin(), \
        this->_mainArrayDeque.end(), this->_secondArrayDeque[this->_positionsDeque[i] - 1]);

        this->_mainArrayDeque.insert(insertPosition, \
        this->_secondArrayDeque[this->_positionsDeque[i] - 1]);
        addedCount++;
    }

    if (!this->_isEven)
    {
        insertPosition = std::lower_bound(this->_mainArrayDeque.begin(), \
        this->_mainArrayDeque.end(), this->_lastValue);
        this->_mainArrayDeque.insert(insertPosition, this->_lastValue);
    }
}
/* #endregion */


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
        if (i + 1 < argc)
        {
            this->_mVectorPair.push_back(std::make_pair(this->_mVector[i], this->_mVector[i + 1]));
        }
    }
    if (!this->_isEven && !this->_mVector.empty())
    {
        this->_lastValue = this->_mVector.back();
    }
}

void PmergeMe::_sortPairDescendingVector()
{
    for (size_t i = 0; i < this->_mVectorPair.size(); i++)
    {
        if (this->_mVectorPair.at(i).first < this->_mVectorPair.at(i).second)
        {
            std::swap(this->_mVectorPair.at(i).first, this->_mVectorPair.at(i).second);
        }
    }
}

void PmergeMe::_mergeVector(std::vector<std::pair<int, int> > &mVector, int begin, int middle, int end)
{
    std::vector<std::pair<int, int> > left(middle - begin + 1);
    std::vector<std::pair<int, int> > right(end - middle);

    std::copy(mVector.begin() + begin, mVector.begin() + middle + 1, left.begin());
    std::copy(mVector.begin() + middle + 1, mVector.begin() + end + 1, right.begin());

    size_t topLeft = 0;
    size_t topRight = 0;
    size_t topMerge = begin;

    while (topLeft < left.size() && topRight < right.size())
    {
        if (left.at(topLeft).first <= right.at(topRight).first)
        {
            mVector.at(topMerge) = left.at(topLeft);
            topLeft++;
        }
        else
        {
            mVector.at(topMerge) = right.at(topRight);
            topRight++;
        }
        topMerge++;
    }

    while (topLeft < left.size())
    {
        mVector.at(topMerge) = left.at(topLeft);
        topLeft++;
        topMerge++;
    }

    while (topRight < right.size())
    {
        mVector.at(topMerge) = right.at(topRight);
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
        this->_mergeVector(this->_mVectorPair, begin, middle, end);
    }
}

void PmergeMe::_fillMainAndSecondArrayVector()
{
    size_t i = 0;

    this->_mainArrayVector.push_back(this->_mVectorPair.at(i).second);
    while (i < this->_mVectorPair.size())
    {
        this->_mainArrayVector.push_back(this->_mVectorPair.at(i).first);
        this->_secondArrayVector.push_back(this->_mVectorPair.at(i).second);
        i++;
    }
}

void PmergeMe::_fillSequenceJacobsthalVector()
{
	int index = 3;
	size_t jcobstalIndex;
   	size_t size = this->_secondArrayVector.size();

	while ((jcobstalIndex = generationSequenceJacobsthal(index)) < size - 1)
	{
		this->_sequenceJacobsthalVector.push_back(jcobstalIndex);
		index++;
	}
}

void PmergeMe::_gerenatePositionsVector()
{
  	size_t jacobsIndex = 1;
	size_t lastPos = 1;

    for (size_t i = 0; i < this->_sequenceJacobsthalVector.size(); ++i)
    {
        jacobsIndex  = this->_sequenceJacobsthalVector.at(i);
        this->_positionsVector.push_back(jacobsIndex );
        for (size_t pos = jacobsIndex - 1; pos > lastPos; --pos)
        {
            this->_positionsVector.push_back(pos);
        }
        lastPos = jacobsIndex ;
	}
    for (size_t i = jacobsIndex; i  < this->_secondArrayVector.size(); ++i)
    {
        this->_positionsVector.push_back(i + 1);
    }
}

void PmergeMe::_orderArrayVector()
{
    size_t addedCount = 0;
    std::vector<int>::iterator insertPosition;
    for (size_t i = 0; i < this->_positionsVector.size(); i++)
    {
        insertPosition = std::lower_bound(this->_mainArrayVector.begin(), \
        this->_mainArrayVector.end(), this->_secondArrayVector[this->_positionsVector[i] - 1]);

        this->_mainArrayVector.insert(insertPosition, \
        this->_secondArrayVector[this->_positionsVector[i] - 1]);
        addedCount++;
    }

    if (!this->_isEven)
    {
        insertPosition = std::lower_bound(this->_mainArrayVector.begin(), \
        this->_mainArrayVector.end(), this->_lastValue);
        this->_mainArrayVector.insert(insertPosition, this->_lastValue);
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
