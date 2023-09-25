// #include<bits/stdc++.h>

// using namespace std;

// //Data structure to store the line segments
// struct Segment
// {
//     int start, end;
// };

// // Function for comparing two segments. Segment s1 come before s2 if s1's start
// // is smaller than s2's start
// bool comp(Segment s1, Segment s2)
// {
//     return s1.start < s2.start;
// }

// // Find the largest set of non intersecting line segments
// // Eg: Input: n = 4,  
// //        segments[] = {(1, 8), (2, 5), (4, 7), (6, 10)}
// //    Output: 3
// //    Explanation: All possible set of non intersecting line 
// // segments are {(1, 8), (2, 5), (4, 7)} or 
// // {(2, 5), (4, 7), (6, 10)}.
// int findMaxNonIntersectingSegments(Segment segments[], int n)
// {
//     // Trivial case
//     if (n == 0)
//         return 0;

//     // sort Segments in increasing order of their start points
//     sort(segments, segments + n, comp);

//     // take first segment as previous and its end point as last_point 
//     int last_point = segments[0].end;
//     int count = 1;

//     // consider rest of the segments one by one
//     for (int i = 1; i < n; i++)
//     {
//         if (last_point < segments[i].start)
//         {
//             // non intersecting segment found
//             last_point = segments[i].end;
//             count++;
//         }
//     }

//     return count;
// }

// // main function
// int main()
// {
//     int n;
//     cin >> n;

//     // an array of segments
//     Segment segments[n];
//     for (int i = 0; i < n; i++)
//         cin >> segments[i].start >> segments[i].end;

//     // find largest set of non intersecting segments
//     cout << findMaxNonIntersectingSegments(segments, n);

//     return 0;
// }
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    sort(segments.begin(), segments.end(), compare);

    int current_right_end = -1;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (segments[i].first > current_right_end) {
            current_right_end = segments[i].second;
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
