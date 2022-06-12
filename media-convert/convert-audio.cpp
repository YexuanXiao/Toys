#include <filesystem>
#include <format>
#include <iostream>
#include <deque>

namespace fs = std::filesystem;

template<typename T> requires requires(T t,typename T::value_type u) { t.push_back(u); }
void recursive_find_audio(const fs::path& p, T& v_p)
{
    auto begin = fs::recursive_directory_iterator(p);
    auto end = fs::recursive_directory_iterator();
    while (begin != end)
    {
        try {
            const auto& entry = *begin;
            if (entry.is_regular_file())
            {
                const auto ext = entry.path().extension().string();
                if (ext == ".tak" || ext == ".tta" || ext == ".wav"|| ext == ".m4a") {
                    v_p.push_back(entry.path());
                    std::cout << "Added " << entry.path() << " to list." << std::endl;
                }
            }
            else {
                // other mysterious type
            }
            ++begin;
        }
        catch (fs::filesystem_error a) {
            ++begin;
        }
    }
}
int main()
{
    std::vector<fs::path> v_p;
    recursive_find_audio(fs::current_path(), v_p);
    for (auto& p1:v_p) {
        fs::path p2 = p1.parent_path();
        p2 /= p1.stem();
        std::system(std::format("ffmpeg -i \"{}\" \"{}{}\"",p1.string(), p2.string(), ".flac").c_str());
        fs::remove(p1);
    }
}