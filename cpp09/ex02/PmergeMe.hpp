#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstdlib>
#include <deque>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

class PmergeMe
{
  private:
    bool _isEven;
    int _lastValue;
    int _tempValue[2];

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

    void _fillArrayDeque(int const argc, char const *argv[]);
    void _separateArrayDeque(int const argc);
    void _sortPairDescendingDeque();
    void _mergeSortDeque( int begin, int end);
    void _mergeDeque(std::deque<std::pair<int, int> > &mDeque, int begin, int middle, int end);
    void _fillMainAndSecondArrayDeque();
    void _fillSequenceJacobsthalDeque();
    void _gerenatePositionsDeque();
    void _orderArrayDeque();

    void _fillArrayVector(int const argc, char const *argv[]);
    void _separateArrayVector(int const argc);
    void _sortPairDescendingVector();
    void _mergeSortVector(int begin, int end);
    void _mergeVector(std::vector<std::pair<int, int> > &mVector, int begin, int middle, int end);
    void _fillMainAndSecondArrayVector();
    void _fillSequenceJacobsthalVector();
    void _gerenatePositionsVector();
    void _orderArrayVector();

  public:
    PmergeMe(int const argc, char const *argv[]);
    PmergeMe(const PmergeMe &src);

    ~PmergeMe();
    PmergeMe &operator=(PmergeMe const &rhs);
};

#endif
