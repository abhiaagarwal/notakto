// Copyright 2017 <Abhi Agarwal>
#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

#include "Piece.hpp"

class Board {
public:
  Board();
  ~Board();

  void fill();
  void eliminate();

  bool checkForElimination() const;
  bool isEliminated() const;

  piece_t get(const size_t&, const size_t&) const;
  void set(const size_t&, const size_t&);
private:
  static constexpr std::size_t m_board_size = 3;

  std::array<std::array<piece_t, m_board_size>, m_board_size> m_board;
  bool m_is_eliminated = false;
};

using board_t = Board;
