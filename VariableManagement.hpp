#include <type_traits>
#include <string>
#include <variant>
#include <charconv>
template <typename T>
class UserVariable {
public:
	T value;

	void var_UIF__(std::wstring input) {
        std::wstring varName;
        int equalSignPosition;
        //Få varName
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == L' ' && input[i + 1] == L'=') { 
                equalSignPosition = i + 1;
                break;
            }
            else if (input[i] == L'=') {
                equalSignPosition = i;
                break;
            }
            else varName.push_back(input[i]);
        };
        
        std::wstring varValue;
        for (int i = equalSignPosition; i < input.size(); ++i) {
            if (input[i] == L';') break;
            if (input[i] == L' ') continue;
            varValue.push_back(input[i]);
        }

        Value val = GetValueDataType(varValue);
	};

private:
    inline static bool isInt = false;
    inline static bool isString = false;
    inline static bool isDouble = false;
    inline static bool isFloat = false;

    using Value = std::variant<int, double, std::string>;
    Value GetValueDataType(std::wstring str) {
        std::string s(str.begin(), str.end()); //konvertera till string eftersom from_chars expect chars inte wchars_t
        int integer;
        auto fromChars1 = std::from_chars(s.data(), s.data() + s.size(), integer); 
        //Scannar varje char från s.data() till s.data() + s.size() ifall det kan vara int och lägger in i integer :)
        if (fromChars1.ec == std::errc && fromChars1.ptr == s.data() + s.size()) return i;

        double d;
        auto fromChars2 = std::from_chars(s.data(), s.data() + s.size(), d);
        if (fromChars2.ec == std::errc && fromChars2.ptr == s.data() + s.size()) return d;

        return s;
    }
};