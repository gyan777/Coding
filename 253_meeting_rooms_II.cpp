
//Uses separate vectors for start and end times

int minMeetingRooms(vector<Interval>& intervals) {
    vector<int> starts, ends;
    for (auto i : intervals) {
        starts.push_back(i.start);
        ends.push_back(i.end);
    }
    sort(begin(starts), end(starts));
    sort(begin(ends), end(ends));
    int e = 0, rooms = 0, available = 0;
    for (int start : starts) {
        while (ends[e] <= start) {
            ++e;
            ++available;
        }
        available ? --available : ++rooms;
    }
    return rooms;
}
