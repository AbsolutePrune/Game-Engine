# Game-Engine

Use cmake to build

Controller adds movement controls - W = up, A = left, S = down, D = right, Q = away, E = towards

Player component throws an exception when B is pressed which is handled in the Entity tick function by
removing the entities components then removing the entity itself to avoid a crash

Doxygen comments in the header files as per the lab instructions