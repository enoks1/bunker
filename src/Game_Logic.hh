#include <iostream>
#include <stdint.h>
#include <assert.h>
#include <array>

#include "Parameters.hh"

class Game_Logic
{
	enum Block_Type {
		nil,
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
		private:
			Block_Type type = nil;
			int32_t state = SPAWN;
			int32_t rotation = NONE;
		public:
			Block(Block_Type type) {
				this->type = type;
			}
			Block_Type Get_Type() {
				return this->type;
			}
	};

	class Active_Block : public Block {
		private:
			Block *block = nullptr;

			void Attach_Block(Block *b) {
				if (block == nullptr) {
					this->block = b;
				}
			}
			void Detach_Block() {
				if (this->block != nullptr) {
					delete this->block;
					this->block = nullptr;
				}
			}

		public:
			Active_Block(Block_Type block_type) :Block(block_type) {}

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
			int32_t Get_X() {
				return this->x;
			}
			int32_t Get_Y() {
				return this->y;
			}
			bool Is_Occupied() {
				return this->occupied;
			}
			void Make_Occupied() {
				this->occupied = true;
			}
	};

	class Board_State {
		private:
			std::array<Point, 200> board;
			std::array<Block_Type, 7> bag{L, J, O, S, Z, I, T};
		public:
			Board_State() {
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
			void Fill_Coordinate(int32_t x, int32_t y) {
				for (auto i = 0; i < 200; ++i) {
					if (board[i].Get_X() == x && board[i].Get_Y() == y) {
						board[i].Make_Occupied();
					}
				}
			}
			void Spawn_Block(Active_Block active_block) {
				switch (active_block.Get_Type()) {
					case L:
						break;
					case J:
						break;
					case O:
						Fill_Coordinate(4, 0);
						Fill_Coordinate(4, 1);
						Fill_Coordinate(5, 0);
						Fill_Coordinate(5, 1);
						break;
					case S:
						break;
					case Z:
						break;
					case I:
						break;
					case T:
						break;
					default:
						;
				}
			}
			void Move_Left_Block() {}
			void Move_Right_Block() {}
			void Slow_Drop_Block() {}
			void Hard_Drop_Block() {}
			void Left_Rotate_Block() {}
			void Right_rotate_Block() {}
	};

	public:
	void Spawn(Block_Type block_type) {
		Active_Block active_block = Active_Block(block_type); // Make new block.
		active_block.Swap_Active(&active_block); // Make it active.
		board.Spawn_Block(active_block); // Pass it to the enviroment.
	}
	void Print() {
		this->board.Dump_Board();
	}
	Game_Logic() :board{Board_State()}, active_block{Active_Block(nil)}{
		Spawn(O);
		Print();
	}

	private:
	Board_State board;
	Active_Block active_block;
};
