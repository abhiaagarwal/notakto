// Copyright 2017 <Abhi Agarwal>
#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

#include "Board.hpp"

class Gameboard {
public:
  Gameboard();
  ~Gameboard();

  void fill();
  void eliminate(const size_t&);

  bool checkForElimination() const;
  size_t getIndexForElimination() const;

  piece_t get(const size_t&, const size_t&, const size_t&) const;
  void set(const size_t&, const size_t&, const size_t&);
private:
  static constexpr std::size_t m_num_boards = 3;
  std::array<board_t, m_num_boards> m_gameboard;
};

using gameboard_t = Gameboard;
