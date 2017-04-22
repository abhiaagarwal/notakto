// Copyright 2017 <Abhi Agarwal>
#include "Board.hpp"

Board::Board() { fill(); }

Board::~Board() { fill(); }

void Board::fill() {
  for (auto &row : m_board) {
    for (auto &piece : row) {
      piece = Piece::Blank;
    }
  }
  m_is_eliminated = false;
}

void Board::eliminate() {
  for (auto &row : m_board) {
    for (auto &piece : row) {
      piece = Piece::Eliminate;
    }
  }
  m_is_eliminated = true;
}

piece_t Board::get(const size_t& x, const size_t& y) const {
  return m_board[y][x];
}

void Board::set(const size_t& x, const size_t& y) {
  m_board[y][x] = Piece::Marked;
}

bool Board::checkForElimination() const {
  std::array<uint8_t, 2> markers{{0, 0}};

  for (size_t i = 0; i < m_board_size; ++i) {
    for (size_t j = 0; j < m_board_size; ++j) {
      if (m_board[j][i] == Piece::Marked) {
        ++markers[0];
      }
      if (m_board[i][j] == Piece::Marked) {
        ++markers[1];
      }
    }
  }
  for (const auto &marker : markers) {
    if (marker == m_board_size) {
      return true;
    }
  }

  // There are two diagonal cases.
  for(size_t i = 0; i < 2; i++) {

  }
  return false;
}

bool Board::isEliminated() const {
  return m_is_eliminated;
}
