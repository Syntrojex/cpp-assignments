#include <iostream>

using namespace std;

template <typename T>
class ArrayList {
private:
    T* arr;
    int capacity;
    int currentSize;

    void resize(int newCapacity)
    {
        T* newData = new T[newCapacity];
        for (int i = 0; i < currentSize; i++)
        {
            newData[i] = arr[i];
        }
        delete[] arr;
        arr = newData;
        capacity = newCapacity;
    }

public:
    ArrayList(int initialCapacity = 4)
    {
        capacity = initialCapacity;
        if (capacity < 1)
        {
            capacity = 1;
        }
        currentSize = 0;
        arr = new T[capacity];
    }

    ~ArrayList() 
    { 
        delete[] arr;
    }

    ArrayList(const ArrayList& other) 
    {
        capacity = other.capacity;
        currentSize = other.currentSize;
        arr = new T[capacity];
        for (int i = 0; i < currentSize; i++)
        {
            arr[i] = other.arr[i];
        }
    }

    ArrayList& operator=(const ArrayList& other) 
    {
        if (this != &other) 
        {
            delete[] arr;
            capacity = other.capacity;
            currentSize = other.currentSize;
            arr = new T[capacity];
            for (int i = 0; i < currentSize; i++)
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    // Time: O(1)  Space: O(1)
    void push_back(const T& item)
    {
        if (currentSize == capacity)
        {
            resize(capacity * 2);
        }
        arr[currentSize++] = item;
    }

    // Time: O(n). Space: O(1)
    void removeAt(int index)
    {
        if (index < 0 || index >= currentSize)
        {
            return;
        }
        for (int i = index; i < currentSize - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        currentSize--;
    }

    T& get(int index) 
    { 
        return arr[index]; 
    }

    const T& get(int index) const 
    { 
        return arr[index]; 
    }

    void set(int index, const T& val)
    { 
        arr[index] = val;
    }

    int  size()    const 
    { 
        return currentSize;
    }

    bool isEmpty() const 
    {
        return currentSize == 0;
    }
};

const int ACTIVE = 0;
const int SELECTED = 1;
const int WITHDRAWN = 2;

string statusToString(int s)
{
    if (s == ACTIVE)
    {
        return "ACTIVE";
    }

    if (s == SELECTED)
    {
        return "SELECTED";
    }

    if (s == WITHDRAWN)
    {
        return "WITHDRAWN";
    }
    return "UNKNOWN";
}

class Candidate {
public:
    int id;
    string name;
    string university;
    double cgpa;
    int experienceYears;
    double technicalScore;
    double interviewScore;
    ArrayList<string> skills;
    int status;

    Candidate(): id(-1), cgpa(0), experienceYears(0), technicalScore(0),interviewScore(0), skills(4), status(ACTIVE) {}

    Candidate(int id_, string name_, string uni_, double cgpa_, int exp_,double tech_, double interview_, ArrayList<string> skills_): id(id_), name(name_), university(uni_), cgpa(cgpa_),experienceYears(exp_), technicalScore(tech_), interviewScore(interview_),skills(skills_), status(ACTIVE) {}

    // Time: O(k) Space: O(1)
    bool hasSkill(const string& skill) const 
    {
        for (int i = 0; i < skills.size(); i++) 
        {
            if (skills.get(i) == skill)
            {
                return true;
            }
        }
        return false;
    }

    // Time: O(k * R) Space: O(1)
    int relevantSkillCount() const 
    {
        static const string relevant[] = 
        {
            "C++", "Python", "Machine Learning", "Deep Learning", "Java",
            "Data Structures", "SQL", "TensorFlow", "PyTorch", "NLP",
            "Computer Vision", "Statistics"
        };
        int relevantCount = 12;
        int count = 0;
        for (int i = 0; i < skills.size(); i++) 
        {
            for (int r = 0; r < relevantCount; r++) 
            {
                if (skills.get(i) == relevant[r]) 
                { 
                    count++; 
                    break;
                }
            }
        }
        return count;
    }

    // Time: O(1). Space: O(1)
    double finalScore() const 
    {
        double cgpaScore = (cgpa / 4.0) * 100.0;
        return 0.40 * cgpaScore + 0.35 * technicalScore + 0.25 * interviewScore;
    }

    void print() const 
    {
        cout << "  [" << id << "] " << name << " | " << university
            << " | CGPA: " << cgpa
            << " | Exp: " << experienceYears << "y"
            << " | Tech: " << technicalScore
            << " | Interview: " << interviewScore
            << " | Skills: ";
        for (int i = 0; i < skills.size(); i++) 
        {
            cout << skills.get(i);
            if (i != skills.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << " | Status: " << statusToString(status) << endl;
    }
};

class Stage {
public:
    string stageName;
    ArrayList<Candidate> candidates;
    Stage* next;

    Stage(const string& name) : stageName(name), candidates(8), next(nullptr) {}
};

class RecruitmentPipeline {
private:
    Stage* head;
    ArrayList<Candidate> withdrawnCandidates;

    struct IdStages {
        int id;
        ArrayList<string> foundIn;
        IdStages() : id(-1), foundIn(4) {}
        IdStages(int id_) : id(id_), foundIn(4) {}
    };

public:
    RecruitmentPipeline() : head(nullptr), withdrawnCandidates(8) {}

    ~RecruitmentPipeline() 
    {
        Stage* current = head;
        while (current) 
        {
            Stage* next = current->next;
            delete current;
            current = next;
        }
    }

    // Time: O(S) Space: O(1)
    void addStageAtEnd(const string& name) 
    {
        Stage* newStage = new Stage(name);
        if (!head)
        { 
            head = newStage;
            return; 
        }

        Stage* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newStage;
    }

    // Time: O(S). Space: O(1)
    Stage* findStage(const string& name) 
    {
        Stage* temp = head;
        while (temp) 
        {
            if (temp->stageName == name)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Time: O(S). Space: O(1)
    Stage* findPrevStage(const string& name) 
    {
        if (!head)
        {
            return nullptr;
        }
        if (head->stageName == name)
        {
            return nullptr;
        }
        Stage* temp = head;
        while (temp->next)
        {
            if (temp->next->stageName == name)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Time: O(S) Space: O(1)
    void insertStage(const string& newStageName, const string& afterStageName) 
    {
        Stage* afterStage = findStage(afterStageName);
        if (!afterStage)
        {
            cout << "ERROR: Stage \"" << afterStageName << "\" does not exist" << endl;
            return;
        }
        if (findStage(newStageName)) 
        {
            cout << "ERROR: Stage \"" << newStageName << "\" already exists"<<endl;
            return;
        }
        Stage* newStage = new Stage(newStageName);
        newStage->next = afterStage->next;
        afterStage->next = newStage;
        cout << "Stage \"" << newStageName << "\" inserted after \"" << afterStageName << "\""<<endl;
    }

    // Time: O(S)  Space: O(1)
    void removeStage(const string& stageName) 
    {
        Stage* target = findStage(stageName);
        if (!target)
        {
            cout << "ERROR: Stage \"" << stageName << "\" not found" << endl;
            return;
        }
        if (!target->candidates.isEmpty()) 
        {
            cout << "REJECTED: Stage \"" << stageName << "\" still has "
                << target->candidates.size() << " candidate(s)" << endl;
            return;
        }
        if (target == head) 
        {
            head = head->next;
        }
        else {
            Stage* prev = findPrevStage(stageName);
            prev->next = target->next;
        }
        delete target;
        cout << "Stage \"" << stageName << "\" removed" << endl;
    }

    void reversePipeline()
    {
        Stage* prev = nullptr;
        Stage* temp = head;
        while (temp)
        {
            Stage* nxt = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nxt;
        }
        head = prev;
        cout << "Pipeline order reversed" << endl;
    }

    // Time: O(S). Space: O(1)
    bool hasCycle() 
    {
        Stage* slow = head;
        Stage* fast = head;
        while (fast && fast->next) 
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    // Time: O(N) worst case, N = total candidates across all stages Space: O(1)
    Stage* locateCandidate(int id, int& idxOut) 
    {
        Stage* temp = head;
        while (temp) 
        {
            for (int i = 0; i < temp->candidates.size(); i++) 
            {
                if (temp->candidates.get(i).id == id) 
                {
                    idxOut = i;
                    return temp;
                }
            }
            temp = temp->next;
        }
        idxOut = -1;
        return nullptr;
    }

    // Time: O(W), W = withdrawn count. Space: O(1)
    int findWithdrawnIndex(int id) 
    {
        for (int i = 0; i < withdrawnCandidates.size(); i++)
        {
            if (withdrawnCandidates.get(i).id == id) return i;
        }
        return -1;
    }

    // Time: O(N). Space: O(1).
    bool addCandidate(const string& stageName, const Candidate& c) {
        int idx;
        Stage* existing = locateCandidate(c.id, idx);
        if (existing != nullptr || findWithdrawnIndex(c.id) != -1) {
            cout << "ERROR: Candidate ID " << c.id << " already exists.\n";
            return false;
        }
        Stage* s = findStage(stageName);
        if (!s) {
            cout << "ERROR: Stage \"" << stageName << "\" not found.\n";
            return false;
        }
        s->candidates.push_back(c);
        cout << "Candidate " << c.id << " added to \"" << stageName << "\".\n";
        return true;
    }

    // Time: O(N^2) worst case. Space: O(N).
    bool checkPipelineIntegrity() {
        ArrayList<IdStages> seen(16);
        Stage* cur = head;
        while (cur) {
            for (int i = 0; i < cur->candidates.size(); i++) {
                int id = cur->candidates.get(i).id;
                int foundAt = -1;
                for (int j = 0; j < seen.size(); j++) {
                    if (seen.get(j).id == id) { foundAt = j; break; }
                }
                if (foundAt == -1) {
                    IdStages entry(id);
                    entry.foundIn.push_back(cur->stageName);
                    seen.push_back(entry);
                }
                else {
                    seen.get(foundAt).foundIn.push_back(cur->stageName);
                }
            }
            cur = cur->next;
        }

        bool corrupted = false;
        for (int i = 0; i < seen.size(); i++) {
            if (seen.get(i).foundIn.size() > 1) {
                if (!corrupted) {
                    cout << "PIPELINE CORRUPTED\n";
                    corrupted = true;
                }
                cout << "Duplicate Candidate: ID = " << seen.get(i).id << "\n";
                cout << "Found in: ";
                for (int k = 0; k < seen.get(i).foundIn.size(); k++) {
                    cout << seen.get(i).foundIn.get(k);
                    if (k != seen.get(i).foundIn.size() - 1) cout << ", ";
                }
                cout << "\n";
            }
        }
        if (!corrupted) cout << "Pipeline integrity OK. No duplicates found.\n";
        return corrupted;
    }

    // Time: O(N + S) -- locate candidate (O(N)) + locate destination (O(S)). Space: O(1).
    bool moveCandidate(int candidateID, const string& destinationStage) {
        int idx;
        Stage* src = locateCandidate(candidateID, idx);
        if (!src) {
            cout << "ERROR: Candidate " << candidateID << " not found in pipeline.\n";
            return false;
        }
        Stage* dest = findStage(destinationStage);
        if (!dest) {
            cout << "ERROR: Destination stage \"" << destinationStage << "\" does not exist.\n";
            return false;
        }
        if (src == dest) {
            cout << "Candidate " << candidateID << " is already in \"" << destinationStage << "\".\n";
            return false;
        }
        Candidate c = src->candidates.get(idx);
        src->candidates.removeAt(idx);
        dest->candidates.push_back(c);
        cout << "Candidate " << candidateID << " moved: " << src->stageName
            << " -> " << dest->stageName << "\n";
        return true;
    }

    // Time: O(N). Space: O(1).
    void withdrawCandidate(int candidateID) {
        int idx;
        Stage* s = locateCandidate(candidateID, idx);
        if (s) {
            Candidate c = s->candidates.get(idx);
            s->candidates.removeAt(idx);
            c.status = WITHDRAWN;
            withdrawnCandidates.push_back(c);
            cout << "Candidate " << candidateID << " withdrawn from \"" << s->stageName << "\".\n";
            return;
        }
        if (findWithdrawnIndex(candidateID) != -1) {
            cout << "Candidate has already withdrawn.\n";
            return;
        }
        cout << "Candidate not found.\n";
    }

    // updateTechnicalScore / updateInterviewScore
    // Time: O(N). Space: O(1).
    void updateTechnicalScore(int candidateID, double newScore) {
        int idx;
        Stage* s = locateCandidate(candidateID, idx);
        if (!s) { cout << "Candidate not found.\n"; return; }
        if (s->stageName != "Technical Interview") {
            cout << "REJECTED: Technical Score can only be updated in \"Technical Interview\" "
                << "(currently in \"" << s->stageName << "\").\n";
            return;
        }
        s->candidates.get(idx).technicalScore = newScore;
        cout << "Candidate " << candidateID << " Technical Score updated to " << newScore << ".\n";
    }

    void updateInterviewScore(int candidateID, double newScore) {
        int idx;
        Stage* s = locateCandidate(candidateID, idx);
        if (!s) { cout << "Candidate not found.\n"; return; }
        if (s->stageName != "HR Interview") {
            cout << "REJECTED: Interview Score can only be updated in \"HR Interview\" "
                << "(currently in \"" << s->stageName << "\").\n";
            return;
        }
        s->candidates.get(idx).interviewScore = newScore;
        cout << "Candidate " << candidateID << " Interview Score updated to " << newScore << ".\n";
    }

    void promoteEligibleCandidates() {
        struct Snap { Stage* s; int originalSize; };
        ArrayList<Snap> snaps(8);
        Stage* cur = head;
        while (cur) {
            Snap sn;
            sn.s = cur;
            sn.originalSize = cur->candidates.size();
            snaps.push_back(sn);
            cur = cur->next;
        }

        int totalPromoted = 0;
        for (int i = 0; i < snaps.size(); i++) {
            Stage* stage = snaps.get(i).s;
            int origSize = snaps.get(i).originalSize;
            if (!stage->next) continue;

            for (int idx = origSize - 1; idx >= 0; idx--) {
                Candidate& c = stage->candidates.get(idx);
                bool eligible = false;

                if (stage->stageName == "Applied") {
                    eligible = (c.cgpa >= 3.0);
                }
                else if (stage->stageName == "Screening") {
                    eligible = (c.cgpa >= 3.2 && c.relevantSkillCount() >= 2);
                }
                else if (stage->stageName == "Technical Interview") {
                    eligible = (c.technicalScore >= 70);
                }
                else if (stage->stageName == "HR Interview") {
                    eligible = (c.technicalScore >= 80 && c.interviewScore >= 75);
                }

                if (eligible) {
                    Candidate moved = c;
                    if (stage->next->stageName == "Selected") moved.status = SELECTED;
                    stage->candidates.removeAt(idx);
                    stage->next->candidates.push_back(moved);
                    cout << "Promoted candidate " << moved.id << ": "
                        << stage->stageName << " -> " << stage->next->stageName << "\n";
                    totalPromoted++;
                }
            }
        }
        cout << "promoteEligibleCandidates() complete. Total promoted: " << totalPromoted << "\n";
    }

    // Time: O(N). Space: O(1)
    void getBestCandidate() {
        Stage* cur = head;
        bool found = false;
        Candidate best;
        while (cur) {
            for (int i = 0; i < cur->candidates.size(); i++) {
                const Candidate& c = cur->candidates.get(i);
                if (!found) {
                    best = c;
                    found = true;
                    continue;
                }
                double bScore = best.finalScore();
                double cScore = c.finalScore();
                bool better = false;
                if (cScore > bScore) {
                    better = true;
                }
                else if (cScore == bScore) {
                    if (c.technicalScore > best.technicalScore) {
                        better = true;
                    }
                    else if (c.technicalScore == best.technicalScore) {
                        if (c.cgpa > best.cgpa) {
                            better = true;
                        }
                        else if (c.cgpa == best.cgpa && c.id < best.id) {
                            better = true;
                        }
                    }
                }
                if (better) best = c;
            }
            cur = cur->next;
        }
        if (!found) { cout << "No candidates in pipeline.\n"; return; }
        cout << "Best Candidate (Final Score = " << best.finalScore() << "):\n";
        best.print();
    }

    // Time: O(N * k), k = avg skills per candidate. Space: O(matches).
    void findCandidatesBySkill(const string& skill) {
        cout << "Candidates with skill \"" << skill << "\":\n";
        bool any = false;
        Stage* cur = head;
        while (cur) {
            for (int i = 0; i < cur->candidates.size(); i++) {
                const Candidate& c = cur->candidates.get(i);
                if (c.hasSkill(skill)) {
                    cout << "  (" << cur->stageName << ") ";
                    c.print();
                    any = true;
                }
            }
            cur = cur->next;
        }
        if (!any) cout << "  None found.\n";
    }

    // Time: O(S). Space: O(1).
    void getMostCrowdedStage() {
        if (!head) { cout << "Pipeline is empty.\n"; return; }
        Stage* best = head;
        Stage* cur = head->next;
        while (cur) {
            if (cur->candidates.size() > best->candidates.size()) best = cur;
            cur = cur->next;
        }
        cout << "Most crowded stage: \"" << best->stageName << "\" with "
            << best->candidates.size() << " candidate(s).\n";
    }


    // Time: O(N + S). Space: O(1).
    void displayStatistics() {
        cout << "\n===================== PIPELINE STATISTICS =====================" << endl;
        int totalCandidates = 0;
        Stage* cur = head;
        while (cur) {
            int n = cur->candidates.size();
            double sumCgpa = 0, sumTech = 0, sumInterview = 0;
            int techCount = 0, interviewCount = 0;
            for (int i = 0; i < n; i++) {
                const Candidate& c = cur->candidates.get(i);
                sumCgpa += c.cgpa;
                if (c.technicalScore > 0) { sumTech += c.technicalScore; techCount++; }
                if (c.interviewScore > 0) { sumInterview += c.interviewScore; interviewCount++; }
            }
            cout << "Stage: " << cur->stageName  << endl;
            cout << "  Candidates: " << n << endl;
            if (n > 0) {
                double avgTech = 0.0;
                if (techCount > 0) avgTech = sumTech / techCount;
                double avgInterview = 0.0;
                if (interviewCount > 0) avgInterview = sumInterview / interviewCount;
                cout << "  Avg CGPA: " << sumCgpa / n  << endl;
                cout << "  Avg Technical Score: " << avgTech  << endl;
                cout << "  Avg Interview Score: " << avgInterview  << endl;
            }
            totalCandidates += n;
            cur = cur->next;
        }
        cout << "Total candidates currently in pipeline: " << totalCandidates << "\n";
        cout << "Withdrawn candidates (outside pipeline): " << withdrawnCandidates.size() << "\n";
    }

    void printPipeline() {
        cout << "Pipeline order: ";
        Stage* cur = head;
        while (cur) {
            cout << cur->stageName << " (" << cur->candidates.size() << ")";
            if (cur->next) cout << " -> ";
            cur = cur->next;
        }
        cout << "\n";
    }
};

void loadSampleData(RecruitmentPipeline& pipeline) {
    ArrayList<string> s1(4); s1.push_back("C++"); s1.push_back("Python");
    pipeline.addCandidate("Applied", Candidate(101, "Ali Ahmed", "FAST", 3.1, 0, 0, 0, s1));

    ArrayList<string> s2(2); s2.push_back("Java");
    pipeline.addCandidate("Applied", Candidate(102, "Sara Khan", "LUMS", 2.8, 1, 0, 0, s2));

    ArrayList<string> s3(4); s3.push_back("Python"); s3.push_back("Machine Learning"); s3.push_back("C++");
    pipeline.addCandidate("Applied", Candidate(103, "Bilal Tariq", "NUST", 3.4, 0, 0, 0, s3));

    ArrayList<string> s4(4); s4.push_back("Python"); s4.push_back("Deep Learning");
    pipeline.addCandidate("Screening", Candidate(104, "Hina Riaz", "FAST", 3.5, 1, 0, 0, s4));

    ArrayList<string> s5(4); s5.push_back("C++"); s5.push_back("Data Structures");
    pipeline.addCandidate("Screening", Candidate(105, "Usman Javed", "GIKI", 3.3, 2, 0, 0, s5));

    ArrayList<string> s6(4); s6.push_back("Python"); s6.push_back("NLP");
    pipeline.addCandidate("Technical Interview", Candidate(106, "Ayesha Noor", "FAST", 3.6, 1, 65, 0, s6));

    ArrayList<string> s7(4); s7.push_back("C++"); s7.push_back("TensorFlow");
    pipeline.addCandidate("Technical Interview", Candidate(107, "Danish Iqbal", "UET", 3.0, 0, 75, 0, s7));

    ArrayList<string> s8(4); s8.push_back("Python"); s8.push_back("Machine Learning"); s8.push_back("PyTorch");
    pipeline.addCandidate("Technical Interview", Candidate(108, "Zara Malik", "FAST", 3.8, 2, 60, 0, s8));

    ArrayList<string> s9(4); s9.push_back("C++"); s9.push_back("Computer Vision");
    pipeline.addCandidate("HR Interview", Candidate(109, "Hamza Sheikh", "LUMS", 3.9, 3, 88, 82, s9));

    ArrayList<string> s10(4); s10.push_back("Java"); s10.push_back("SQL");
    pipeline.addCandidate("HR Interview", Candidate(110, "Mahnoor Fatima", "NUST", 3.2, 1, 70, 60, s10));
}

void runDemoScenario(RecruitmentPipeline& pipeline) {
    cout << "\n--- Loading sample candidates 101-110 ---\n";
    loadSampleData(pipeline);
    pipeline.printPipeline();
    pipeline.checkPipelineIntegrity();

    cout << "\n--- STEP 1: updateTechnicalScore(108, 91) ---" << endl;
    pipeline.updateTechnicalScore(108, 91);

    cout << "\n--- STEP 2: moveCandidate(103, \"Screening\") ---" << endl;
    pipeline.moveCandidate(103, "Screening");

    cout << "\n--- STEP 3: insertStage(\"Online Assessment\", \"Screening\") ---" << endl;
    pipeline.insertStage("Online Assessment", "Screening");
    pipeline.printPipeline();

    cout << "\n--- STEP 4: moveCandidate(106, \"Online Assessment\") ---" << endl;
    pipeline.moveCandidate(106, "Online Assessment");

    cout << "\n--- STEP 5: promoteEligibleCandidates() ---" << endl;
    pipeline.promoteEligibleCandidates();
    pipeline.printPipeline();

    cout << "\n--- STEP 6: withdrawCandidate(110) ---" << endl;
    pipeline.withdrawCandidate(110);
    cout << "(calling again to demonstrate 'already withdrawn'):" << endl;
    pipeline.withdrawCandidate(110);

    cout << "\n--- STEP 7: removeStage(\"HR Interview\") " << endl;
    pipeline.removeStage("HR Interview");

    cout << "\n--- STEP 8: findCandidatesBySkill(\"C++\") ---" << endl;
    pipeline.findCandidatesBySkill("C++");

    cout << "\n--- STEP 9: getBestCandidate() ---" << endl;
    pipeline.getBestCandidate();

    cout << "\n--- STEP 10: reversePipeline() ---" << endl;
    pipeline.reversePipeline();
    pipeline.printPipeline();

    cout << "\n--- STEP 11: displayStatistics() ---" << endl;
    pipeline.displayStatistics();

    cout << "\n--- BONUS: getMostCrowdedStage() ---" << endl;
    pipeline.getMostCrowdedStage();

    cout << "\n--- BONUS: hasCycle() ---" << endl;
    if (pipeline.hasCycle()) {
        cout << "Cycle detected!" << endl;
    }
    else {
        cout << "No cycle detected" << endl;
    }
}

void showMenu() {
    cout << "\n================= RECRUITMENT PIPELINE MENU =================" << endl;
    cout << " 1. Add Candidate" << endl;
    cout << " 2. Move Candidate" << endl;
    cout << " 3. Withdraw Candidate" << endl;
    cout << " 4. Update Technical Score" << endl;
    cout << " 5. Update Interview Score" << endl;
    cout << " 6. Promote Eligible Candidates" << endl;
    cout << " 7. Get Best Candidate" << endl;
    cout << " 8. Find Candidates By Skill" << endl;
    cout << " 9. Get Most Crowded Stage" << endl;
    cout << "10. Insert Stage" << endl;
    cout << "11. Remove Stage" << endl;
    cout << "12. Reverse Pipeline" << endl;
    cout << "13. Check Has Cycle" << endl;
    cout << "14. Check Pipeline Integrity" << endl;
    cout << "15. Display Statistics" << endl;
    cout << "16. Print Pipeline Order" << endl;
    cout << "17. Load Sample Data + Run Full Demo Scenario (Section 18)" << endl;
    cout << " 0. Exit" << endl;
}

int main() {
    RecruitmentPipeline pipeline;
    pipeline.addStageAtEnd("Applied");
    pipeline.addStageAtEnd("Screening");
    pipeline.addStageAtEnd("Technical Interview");
    pipeline.addStageAtEnd("HR Interview");
    pipeline.addStageAtEnd("Selected");

    int choice = -1;

    while (choice != 0) {
        bool inputFailed;
        do {
            showMenu();
            cin >> choice;
            inputFailed = cin.fail();

            if (inputFailed) {
                cout << "ERROR:Try again" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            if (choice < 0 || choice > 17) {
                cout << "ERROR:Try again" << endl;
            }
        } while (inputFailed || (choice < 0 || choice > 17));

        switch (choice) {
        case 1:
        {
            cout << "\n-- Add Candidate --\n";

            int id;
            bool inputFailed;
            do {
                cout << "Enter Candidate ID: ";
                cin >> id;
                inputFailed = cin.fail();

                if (inputFailed) {
                    cout << "ERROR:Try again" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                if (id <= 0) {
                    cout << "ERROR: ID must be greater than 0" << endl;
                }
            } while (inputFailed || (id <= 0));

            string name;
            cout << "Enter Name: ";
            cin >> name;

            string uni;
            cout << "Enter University: ";
            cin >> uni;

            double cgpa;
            do {
                cout << "Enter CGPA (0.0 - 4.0): ";
                cin >> cgpa;
                inputFailed = cin.fail();

                if (inputFailed) {
                    cout << "ERROR:Try again" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                if (cgpa < 0.0 || cgpa > 4.0) {
                    cout << "ERROR: CGPA must be between 0.0 and 4.0" << endl;
                }
            } while (inputFailed || (cgpa < 0.0 || cgpa > 4.0));

            int exp;
            do {
                cout << "Enter Years of Experience: ";
                cin >> exp;
                inputFailed = cin.fail();

                if (inputFailed) {
                    cout << "ERROR:Try again" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                if (exp < 0) {
                    cout << "ERROR: Experience cannot be negative" << endl;
                }
            } while (inputFailed || (exp < 0));

            double tech;
            do {
                cout << "Enter Technical Score (0-100): ";
                cin >> tech;
                inputFailed = cin.fail();

                if (inputFailed) {
                    cout << "ERROR:Try again" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                if (tech < 0.0 || tech > 100.0) {
                    cout << "ERROR: Score must be between 0 and 100" << endl;
                }
            } while (inputFailed || (tech < 0.0 || tech > 100.0));

            double interview;
            do {
                cout << "Enter Interview Score (0-100): ";
                cin >> interview;
                inputFailed = cin.fail();

                if (inputFailed) {
                    cout << "ERROR:Try again" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                if (interview < 0.0 || interview > 100.0) {
                    cout << "ERROR: Score must be between 0 and 100" << endl;
                }
            } while (inputFailed || (interview < 0.0 || interview > 100.0));

            int skillCount;
            do {
                cout << "How many skills? ";
                cin >> skillCount;
                inputFailed = cin.fail();

                if (inputFailed) {
                    cout << "ERROR:Try again" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                if (skillCount < 0 || skillCount > 20) {
                    cout << "ERROR: Enter a value between 0 and 20" << endl;
                }
            } while (inputFailed || (skillCount < 0 || skillCount > 20));

            int cap = skillCount;
            if (cap < 1) cap = 1;
            ArrayList<string> skills(cap);
            for (int i = 0; i < skillCount; i++) {
                string sk;
                cout << "  Skill " << (i + 1) << ": ";
                cin >> sk;
                skills.push_back(sk);
            }

            string stageName;
            cout << "Enter starting stage name (e.g., Applied): ";
            cin >> stageName;
            Stage* st = pipeline.findStage(stageName);
            while (!st) {
                cout << "ERROR: Stage not found. Try again" << endl;
                cout << "Enter starting stage name: ";
                cin >> stageName;
                st = pipeline.findStage(stageName);
            }

            Candidate c(id, name, uni, cgpa, exp, tech, interview, skills);
            pipeline.addCandidate(stageName, c);

            break;
        }

        case 2:
        {
            int id;
            bool inputFailed;
            do {
                cout << "Enter Candidate ID to move: ";
                cin >> id;
                inputFailed = cin.fail();

                if (inputFailed) {
                    cout << "ERROR:Try again" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                if (id <= 0) {
                    cout << "ERROR: ID must be greater than 0" << endl;
                }
            } while (inputFailed || (id <= 0));
            cin.ignore(10000, '\n');

            string dest;
            cout << "Enter destination stage name: ";
            cin >> dest;
            pipeline.moveCandidate(id, dest);
            break;
        }

        case 3:
        {
            int id;
            bool inputFailed;
            do {
                cout << "Enter Candidate ID to withdraw: ";
                cin >> id;
                inputFailed = cin.fail();

                if (inputFailed) {
                    cout << "ERROR:Try again" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                if (id <= 0) {
                    cout << "ERROR: ID must be greater than 0" << endl;
                }
            } while (inputFailed || (id <= 0));

            pipeline.withdrawCandidate(id);
            break;
        }

        case 4:
        {
            int id;
            bool inputFailed;
            do {
                cout << "Enter Candidate ID: ";
                cin >> id;
                inputFailed = cin.fail();

                if (inputFailed) {
                    cout << "ERROR:Try again" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                if (id <= 0) {
                    cout << "ERROR: ID must be greater than 0" << endl;
                }
            } while (inputFailed || (id <= 0));

            double score;
            do {
                cout << "Enter new Technical Score (0-100): ";
                cin >> score;
                inputFailed = cin.fail();

                if (inputFailed) {
                    cout << "ERROR:Try again" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                if (score < 0.0 || score > 100.0) {
                    cout << "ERROR: Score must be between 0 and 100" << endl;
                }
            } while (inputFailed || (score < 0.0 || score > 100.0));

            pipeline.updateTechnicalScore(id, score);
            break;
        }

        case 5:
        {
            int id;
            bool inputFailed;
            do {
                cout << "Enter Candidate ID: ";
                cin >> id;
                inputFailed = cin.fail();

                if (inputFailed) {
                    cout << "ERROR:Try again" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                if (id <= 0) {
                    cout << "ERROR: ID must be greater than 0" << endl;
                }
            } while (inputFailed || (id <= 0));

            double score;
            do {
                cout << "Enter new Interview Score (0-100): ";
                cin >> score;
                inputFailed = cin.fail();

                if (inputFailed) {
                    cout << "ERROR:Try again" << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                if (score < 0.0 || score > 100.0) {
                    cout << "ERROR: Score must be between 0 and 100" << endl;
                }
            } while (inputFailed || (score < 0.0 || score > 100.0));

            pipeline.updateInterviewScore(id, score);
            break;
        }

        case 6:
            pipeline.promoteEligibleCandidates();
            break;

        case 7:
            pipeline.getBestCandidate();
            break;

        case 8:
        {
            string skill;
            cout << "Enter skill to search: ";
            cin >> skill;
            pipeline.findCandidatesBySkill(skill);
            break;
        }

        case 9:
            pipeline.getMostCrowdedStage();
            break;

        case 10:
        {
            string newName;
            cout << "Enter new stage name: ";
            cin >> newName;

            string afterName;
            cout << "Enter stage name to insert after: ";
            cin >> afterName;
            pipeline.insertStage(newName, afterName);
            break;
        }

        case 11:
        {
            string name;
            cout << "Enter stage name to remove: ";
            cin >> name;
            pipeline.removeStage(name);
            break;
        }

        case 12:
            pipeline.reversePipeline();
            break;

        case 13:
            if (pipeline.hasCycle()) {
                cout << "Cycle detected!" << endl;
            }
            else {
                cout << "No cycle detected." << endl;
            }
            break;

        case 14:
            pipeline.checkPipelineIntegrity();
            break;

        case 15:
            pipeline.displayStatistics();
            break;

        case 16:
            pipeline.printPipeline();
            break;

        case 17:
            runDemoScenario(pipeline);
            break;

        case 0:
            cout << "Program Terminated successfully" << endl;
            return 0;

        default:
            break;
        }
    }

    return 0;
}