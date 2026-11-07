#include <iostream>
#include <string>

using namespace std;

struct QuestionItem {
    int id;
    string text;
    string options[4];
    int correctIndex; // 0 for Option 1, 1 for Option 2, etc.
};

// C++ Domain Questions
void loadCppQuestions(QuestionItem arr[]) {
    arr[0] = {1, "Which concept allows using the same function name with different arguments?", {"Encapsulation", "Function Overloading", "Virtual Functions", "Abstraction"}, 1};
    arr[1] = {2, "Which operator cannot be overloaded in C++?", {"+", "==", "::", "[]"}, 2};
    arr[2] = {3, "Which keyword is used to prevent inheritance in C++?", {"sealed", "static", "final", "const"}, 2};
    arr[3] = {4, "What type of inheritance can lead to the diamond problem?", {"Single", "Multiple", "Multilevel", "Hierarchical"}, 1};
    arr[4] = {5, "What is the default access specifier for class members in C++?", {"public", "protected", "private", "internal"}, 2};
    arr[5] = {6, "A class containing at least one pure virtual function is called:", {"Static Class", "Abstract Class", "Template Class", "Friend Class"}, 1};
    arr[6] = {7, "Which of the following is executed automatically when an object is destroyed?", {"Constructor", "Destructor", "Static Method", "Virtual Method"}, 1};
    arr[7] = {8, "Which pointer points to the invoking object inside a member function?", {"base pointer", "super pointer", "this pointer", "self pointer"}, 2};
    arr[8] = {9, "Wrapping data and functions into a single unit is known as:", {"Encapsulation", "Polymorphism", "Inheritance", "Abstraction"}, 0};
    arr[9] = {10, "Which feature of OOP allows code reusability?", {"Polymorphism", "Encapsulation", "Inheritance", "Exception Handling"}, 2};
    arr[10] = {11, "Which of the following cannot be a friend in C++?", {"Function", "Class", "Member Function", "Object"}, 3};
    arr[11] = {12, "Constructors cannot be:", {"Inline", "Overloaded", "Virtual", "Public"}, 2};
    arr[12] = {13, "What is the return type of a constructor?", {"void", "int", "bool", "No return type"}, 3};
    arr[13] = {14, "Which keyword is used to define dynamic memory allocation?", {"malloc", "create", "new", "alloc"}, 2};
    arr[14] = {15, "Which keyword is used to release dynamic memory in C++?", {"free", "delete", "clear", "remove"}, 1};
}

// Environmental Sciences Domain Questions
void loadEvsQuestions(QuestionItem arr[]) {
    arr[0] = {1, "Which layer of the atmosphere contains the ozone layer?", {"Troposphere", "Stratosphere", "Mesosphere", "Thermosphere"}, 1};
    arr[1] = {2, "What is the primary greenhouse gas emitted by human activities?", {"Methane", "Carbon Dioxide", "Nitrous Oxide", "Sulfur Dioxide"}, 1};
    arr[2] = {3, "Toxic chemical accumulation through the food chain is termed:", {"Eutrophication", "Biomagnification", "Bioaccumulation", "Biodegradation"}, 1};
    arr[3] = {4, "Which international agreement focuses on phasing out ozone-depleting substances?", {"Kyoto Protocol", "Paris Agreement", "Montreal Protocol", "Ramsar Convention"}, 2};
    arr[4] = {5, "What causes cultural eutrophication in freshwater lakes?", {"Nitrogen/Phosphorus runoff", "Heavy metal dumping", "Microplastics", "Acid rain"}, 0};
    arr[5] = {6, "Which bacteria is monitored to detect fecal water contamination?", {"Escherichia coli", "Lactobacillus", "Spirulina", "Streptococcus"}, 0};
    arr[6] = {7, "Organisms that generate their own food via photosynthesis are called:", {"Heterotrophs", "Autotrophs", "Saprotrophs", "Detritivores"}, 1};
    arr[7] = {8, "Which ecosystem has the highest net primary productivity per unit area?", {"Tundra", "Tropical Rainforest", "Open Ocean", "Temperate Grassland"}, 1};
    arr[8] = {9, "Minamata disease is caused by toxic exposure to:", {"Lead", "Cadmium", "Arsenic", "Methylmercury"}, 3};
    arr[9] = {10, "Photovoltaic cells directly convert solar energy into:", {"Heat", "Electricity", "Chemical energy", "Kinetic energy"}, 1};
    arr[10] = {11, "Who proposed the 10 percent energy transfer rule in trophic levels?", {"Charles Elton", "Raymond Lindeman", "Eugene Odum", "Arthur Tansley"}, 1};
    arr[11] = {12, "Which toxic gas irreversibly binds to human hemoglobin?", {"Carbon Monoxide", "Ozone", "Nitrogen Dioxide", "Sulfur Hexafluoride"}, 0};
    arr[12] = {13, "A species that plays a critical role in maintaining ecosystem structure is:", {"Invasive", "Keystone", "Endemic", "Exotic"}, 1};
    arr[13] = {14, "The measure of human demand on Earth's ecosystems is known as:", {"Carbon Budget", "Ecological Footprint", "Carrying Capacity", "Biocapacity"}, 1};
    arr[14] = {15, "Ocean acidification is mainly caused by the absorption of:", {"Plastic waste", "Carbon Dioxide", "Nitrogen waste", "Heavy minerals"}, 1};
}

// General Knowledge Domain Questions
void loadGkQuestions(QuestionItem arr[]) {
    arr[0] = {1, "Which is the largest and deepest ocean on Earth?", {"Atlantic Ocean", "Indian Ocean", "Pacific Ocean", "Arctic Ocean"}, 2};
    arr[1] = {2, "What is the chemical symbol for Gold?", {"Ag", "Au", "Fe", "Pb"}, 1};
    arr[2] = {3, "Which is the largest hot desert in the world?", {"Gobi Desert", "Kalahari Desert", "Sahara Desert", "Atacama Desert"}, 2};
    arr[3] = {4, "Where is the International Court of Justice located?", {"Geneva", "The Hague", "Vienna", "New York"}, 1};
    arr[4] = {5, "What is the currency of Japan?", {"Won", "Yuan", "Yen", "Baht"}, 2};
    arr[5] = {6, "Which organ primarily filters human blood?", {"Liver", "Kidneys", "Pancreas", "Lungs"}, 1};
    arr[6] = {7, "Who was the first human to travel into space?", {"Neil Armstrong", "Yuri Gagarin", "Buzz Aldrin", "John Glenn"}, 1};
    arr[7] = {8, "What is the SI unit of electrical resistance?", {"Volt", "Ampere", "Ohm", "Watt"}, 2};
    arr[8] = {9, "Which is the smallest bone in the human body?", {"Femur", "Stapes", "Phalanges", "Ulna"}, 1};
    arr[9] = {10, "Which country is called 'Land of the Midnight Sun'?", {"Norway", "Iceland", "Finland", "Sweden"}, 0};
    arr[10] = {11, "What is the hardest naturally occurring mineral?", {"Corundum", "Quartz", "Diamond", "Topaz"}, 2};
    arr[11] = {12, "Which planet in our solar system is known as the Red Planet?", {"Venus", "Mars", "Jupiter", "Saturn"}, 1};
    arr[11] = {13, "Which river is widely recognized as the longest in the world?", {"Amazon", "Nile", "Yangtze", "Mississippi"}, 1};
    arr[13] = {14, "Which scale measures earthquake magnitude?", {"Beaufort", "Richter", "Kelvin", "Mohs"}, 1};
    arr[14] = {15, "What is the rarest human ABO blood group?", {"O-Negative", "AB-Negative", "B-Negative", "A-Negative"}, 1};
}

// History Domain Questions
void loadHistoryQuestions(QuestionItem arr[]) {
    arr[0] = {1, "In which year did World War I officially end?", {"1917", "1918", "1919", "1920"}, 1};
    arr[1] = {2, "Who was the first Emperor of a unified China?", {"Qin Shi Huang", "Han Wudi", "Sun Tzu", "Kublai Khan"}, 0};
    arr[2] = {3, "The ancient city of Mohenjo-daro is in present-day:", {"India", "Pakistan", "Afghanistan", "Iran"}, 1};
    arr[3] = {4, "Which Roman leader was assassinated on the Ides of March in 44 BCE?", {"Mark Antony", "Julius Caesar", "Nero", "Caligula"}, 1};
    arr[4] = {5, "The storming of the Bastille occurred during which revolution?", {"American", "French", "Russian", "Glorious"}, 1};
    arr[5] = {6, "Which Babylonian king formulated an early written legal code?", {"Hammurabi", "Gilgamesh", "Nebuchadnezzar II", "Sargon"}, 0};
    arr[6] = {7, "The Battle of Hastings in 1066 took place in:", {"France", "Scotland", "England", "Ireland"}, 2};
    arr[7] = {8, "Primary author of the US Declaration of Independence was:", {"George Washington", "Benjamin Franklin", "Thomas Jefferson", "John Adams"}, 2};
    arr[8] = {9, "The fall of the Western Roman Empire traditionally marks:", {"395 CE", "410 CE", "476 CE", "1453 CE"}, 2};
    arr[9] = {10, "Who painted 'The Last Supper'?", {"Michelangelo", "Leonardo da Vinci", "Raphael", "Donatello"}, 1};
    arr[10] = {11, "In which year was the Magna Carta signed by King John?", {"1215", "1258", "1314", "1381"}, 0};
    arr[11] = {12, "Suleiman the Magnificent was a sultan of which empire?", {"Safavid", "Ottoman", "Mughal", "Umayyad"}, 1};
    arr[12] = {13, "What was the capital of the Byzantine Empire until 1453?", {"Alexandria", "Athens", "Constantinople", "Rome"}, 2};
    arr[13] = {14, "The Rosetta Stone was crucial for translating:", {"Cuneiform", "Linear A", "Egyptian Hieroglyphs", "Aramaic"}, 2};
    arr[14] = {15, "Who led the Bolsheviks during the 1917 October Revolution?", {"Joseph Stalin", "Leon Trotsky", "Vladimir Lenin", "Alexander Kerensky"}, 2};
}
