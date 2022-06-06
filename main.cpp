#include <iostream>
#include <vector>
#include "LineStorage.h"
#include "Input.h"
#include "Shifter.h"
#include "Sorter.h"
#include "Output.h"
#include "Searcher.h"
#include "Graphics.h"
int main() {
    Graphics graphics;
    graphics.welcome();
    LineStorage data;
    Input input;
    input.readFile(data);
    graphics.drawLine();
    Shifter shifter;
    shifter.makeShift(data);
    Sorter sorter(new QuickSort);
    sorter.doSort(data);
    Output output;
    output.showLines(data.getConnectedLines());
    graphics.drawLine();
    Searcher searcher(input.readSearchStrategy());
    graphics.drawLine();
    input.readPattern(searcher);
    graphics.drawLine();
    output.showLines(searcher.doSearch(data));
    system("pause");
    return 0;
}
