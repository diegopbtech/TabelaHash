CXX = g++        
CXXFLAGS = -Wall -g  
TARGET = programa
SRC = main.cpp PrimeiroNivel.cpp SegundoNivel.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
