#include <iostream>
#include <chrono>

enum class ProfessionalLevel { Primary, Intermediate, Advanced };
enum class EducationLevel { Bachelor, Master, Doctor };
enum class CompetitionLevel { City, Province, National };
enum class AchievementType { InventionPatent, UtilityModelPatent, DesignPatent, SoftwareCopyright, OtherRegistration };

class WolfReputation {
private:
    int reputation = 0;
    std::chrono::system_clock::time_point last_achievement_time;

    void checkInactivity() {
        if (last_achievement_time.time_since_epoch().count() == 0) return;

        auto now = std::chrono::system_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(
            now - last_achievement_time);
        
        if (duration.count() >= 31536000) {
            reputation = 0;
        }
    }

public:
    void addQualification(ProfessionalLevel level) {
        checkInactivity();
        switch(level) {
            case ProfessionalLevel::Primary: reputation += 1; break;
            case ProfessionalLevel::Intermediate: reputation += 2; break;
            case ProfessionalLevel::Advanced: reputation += 3; break;
        }
        last_achievement_time = std::chrono::system_clock::now();
    }

    void addEducation(EducationLevel level) {
        checkInactivity();
        switch(level) {
            case EducationLevel::Bachelor: reputation += 10; break;
            case EducationLevel::Master: reputation += 20; break;
            case EducationLevel::Doctor: reputation += 30; break;
        }
        last_achievement_time = std::chrono::system_clock::now();
    }

    void addCompetition(CompetitionLevel level) {
        checkInactivity();
        switch(level) {
            case CompetitionLevel::City: reputation += 15; break;
            case CompetitionLevel::Province: reputation += 20; break;
            case CompetitionLevel::National: reputation += 50; break;
        }
        last_achievement_time = std::chrono::system_clock::now();
    }

    void addAchievement(AchievementType type) {
        checkInactivity();
        switch(type) {
            case AchievementType::InventionPatent: reputation += 20; break;
            case AchievementType::UtilityModelPatent: reputation += 30; break;
            case AchievementType::DesignPatent: reputation += 35; break;
            case AchievementType::SoftwareCopyright: reputation += 40; break;
            case AchievementType::OtherRegistration: reputation += 50; break;
        }
        last_achievement_time = std::chrono::system_clock::now();
    }

    int getReputation() {
        checkInactivity();
        return reputation;
    }
};

int main() {
    WolfReputation wolf;
    
    wolf.addQualification(ProfessionalLevel::Advanced);
    wolf.addEducation(EducationLevel::Master);
    wolf.addCompetition(CompetitionLevel::National);
    wolf.addAchievement(AchievementType::SoftwareCopyright);
    
    std::cout << "当前声望: " << wolf.getReputation() << std::endl;
    
    return 0;
}