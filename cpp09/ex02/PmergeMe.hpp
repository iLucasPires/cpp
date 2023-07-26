#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

#define MICROSECONDS 1000000.0

class PmergeMe
{
  private:
    bool _isEven;
    int _lastValue;
    clock_t _tempDeque;
    clock_t _tempVector;

    std::deque<int> _mDeque;
    std::deque<std::pair<int, int> > _mDequePair;

    std::vector<int> _mVector;
    std::vector<std::pair<int, int> > _mVectorPair;

    std::deque<int> _mainArrayDeque;
    std::deque<int> _secondArrayDeque;

    std::vector<int> _mainArrayVector;
    std::vector<int> _secondArrayVector;

    std::deque<int> _sequenceJacobsthalDeque;
    std::vector<int> _sequenceJacobsthalVector;

    std::deque<int> _positionsDeque;
    std::vector<int> _positionsVector;


    bool _fillArrayDeque(int const argc, char const *argv[]);
    void _separateArrayDeque(int const argc);
    void _sortPairDescendingDeque();
    void _mergeSortDeque( int begin, int end);
    void _mergeDeque(std::deque<std::pair<int, int> > &mDeque, int begin, int middle, int end);
    void _fillMainAndSecondArrayDeque();
    void _fillSequenceJacobsthalDeque();
    void _gerenatePositionsDeque();
    void _orderArrayDeque();

    bool _fillArrayVector(int const argc, char const *argv[]);
    void _separateArrayVector(int const argc);
    void _sortPairDescendingVector();
    void _mergeSortVector(int begin, int end);
    void _mergeVector(std::vector<std::pair<int, int> > &mVector, int begin, int middle, int end);
    void _fillMainAndSecondArrayVector();
    void _fillSequenceJacobsthalVector();
    void _gerenatePositionsVector();
    void _orderArrayVector();

  public:
    PmergeMe();
    PmergeMe(int const argc, char const *argv[]);
    PmergeMe(const PmergeMe &src);

    ~PmergeMe();
    PmergeMe &operator=(PmergeMe const &rhs);

    void printTime(int const argc);
    void printBeforeAndAfterDeque();
    void printBeforeAndAfterVector();
    bool ford_johnson_with_vector(int const argc, char const *argv[]);
    bool ford_johnson_with_deque(int const argc, char const *argv[]);
};

#endif
