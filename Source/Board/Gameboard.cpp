// Copyright 2017 <Abhi Agarwal>
#include "Gameboard.hpp"

Gameboard::Gameboard() { fill(); }

Gameboard::~Gameboard() { fill(); }

void Gameboard::fill() {
  for (auto &board : m_gameboard) {
    board.fill();
  }
}

void Gameboard::eliminate(const size_t &board_num) {
  m_gameboard[board_num].eliminate();
}

bool Gameboard::checkForElimination() const {
  for (const auto &board : m_gameboard) {
    if (board.checkForElimination()) {
      return true;
    }
  }
  return false;
}

size_t Gameboard::getIndexForElimination() const {
  for(size_t i = 0; i < m_num_boards; ++i) {
    if(m_gameboard[i].checkForElimination() && !m_gameboard[i].isEliminated()) {
      // If the Gameboard has already been eliminated, don't do anything.
      return i;
    }
  }
  return m_num_boards + 1; // This shouldn't happen!
}

piece_t Gameboard::get(const size_t &board_num, const size_t &x,
                       const size_t &y) const {
  return m_gameboard[board_num].get(x, y);
}

void Gameboard::set(const size_t &board_num, const size_t &x, const size_t &y) {
  m_gameboard[board_num].set(x, y);
}
