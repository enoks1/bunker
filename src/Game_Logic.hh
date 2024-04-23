#include <iostream>
#include <stdint.h>
#include <assert.h>
#include <array>

#include "Parameters.hh"

class Game_Logic {
	enum Block_Type {
		L,
		J,
		O,
		S,
		Z,
		I,
		T
	};

	enum Block_Position {
		SPAWN,
		CLOCKWISE,
		ANTI_CLOCKWISE,
		MIRROR
	};

	enum Block_Rotation {
		NONE,
		RIGHT,
		LEFT
	};

	class Block {
		int32_t type;
		int32_t state = SPAWN;
		int32_t rotation = NONE;

		std::array<Block_Type, 7> bag{L, J, O, S, Z, I, T};
	};

	class Active_Block {
		private:
			Block *block = nullptr;
			void Attach_Block(Block *b) {
				if (block == nullptr) {
					this->block = b;
				}
			}
			void Detach_Block() {
				if (this->block != nullptr) {
					this->block = nullptr;
				}
			}

		public:
			void Swap_Active(Block *active) {
				Detach_Block();
				Attach_Block(active);
			}
	};

	class Point {
		private:
			int32_t x, y;
			bool occupied;
		public:
			Point() {}
			Point(int32_t x, int32_t y, bool occupied) {
				this->x = x;
				this->y = y;
				this->occupied = occupied;
			}
			bool Is_Occupied() {
				return this->occupied;
			}
	};

	class Board {
		private:
			std::array<Point, 200> board;
		public:
			Board() {
				auto count = 0;
				for (int32_t i = 0; i < 20; ++i) {
					for (int32_t j = 0; j < 10; ++j) {
						this->board[count++] = Point(j, i, false);
					}
				}
			}
			void Dump_Board() {
				std::cout << "[BOARD]" << std::endl;
				for (auto i = 0; i < board.size(); ++i) {
					if (i % 10 == 0 && i != 0) {
						std::cout << std::endl;
					}
					if (board[i].Is_Occupied()) {
						std::cout << "0";
					} else {
						std::cout << "_";
					}
				} 
				std::cout << std::endl;
			}
			// TODO
			void spawn_block() {}
			void move_left_block() {}
			void move_right_block() {}
			void slow_drop_block() {}
			void hard_drop_block() {}
			void left_rotate_block() {}
			void right_rotate_block() {}
	};

	public:
	Game_Logic() :board{Board()} {}
	void Print_Board() {
		this->board.Dump_Board();
	}
	private:
	Board board;
};
