'''
This is a solution in Python for https://open.kattis.com/problems/includescoring
'''
import sys
import math


SCORES = [-1, 100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]

class Participant:

    def __init__(self, problems_solved, penalty, submit_timestamp, extra_point):
        self.problems_solved = problems_solved
        self.penalty = penalty
        self.submit_timestamp = submit_timestamp
        self.extra_point = extra_point
        self.rank = -1
        self.score = None
        self.did_not_participate = problems_solved == 0 and penalty == 0 and submit_timestamp == 0 and extra_point == 0

    def is_tied_with(self, participant):
        return self.problems_solved == participant.problems_solved \
            and self.penalty == participant.penalty \
            and self.submit_timestamp == participant.submit_timestamp
        
class Contest:

    def __init__(self):
        self.participants = []

    def score_by_rank(self, rank):
        return 0 if rank > 30 else SCORES[rank]

    def assign_ranks(self):
        unique_problems_solved = list(set([participant.problems_solved for participant in self.participants]))
        unique_problems_solved.sort(key=lambda x: -x)
        rank = 1
        previous_participant = None
        for problems_solved in unique_problems_solved:
            first_order_participants = [participant for participant in self.participants if participant.problems_solved == problems_solved and not participant.did_not_participate]
            unique_penalties = list(set([participant.penalty for participant in first_order_participants]))
            unique_penalties.sort()
            for penalty in unique_penalties:
                second_order_participants = [participant for participant in first_order_participants if participant.penalty == penalty]
                
                second_order_participants.sort(key=lambda x: x.submit_timestamp)
                
                for participant in second_order_participants:
                    if previous_participant == None:
                        participant_rank = rank
                    else:
                        if participant.is_tied_with(previous_participant):
                            participant_rank = previous_participant.rank
                        else:
                            participant_rank = rank + 1
                            rank = rank + 1
                            
                    participant.rank = participant_rank
                    previous_participant = participant

    def assign_scores(self):
        self.assign_ranks()
        tied_participants = []
        previous_participant = None
        participant_list = [participant for participant in self.participants]
        participant_list.sort(key=lambda x: x.rank)
        for participant in participant_list:
            if participant.rank == -1:
                participant.score = 0
                continue
            participant.score = self.score_by_rank(participant.rank) + participant.extra_point
            if previous_participant == None:
                tied_participants.append(participant)
            else:
                if previous_participant.rank == participant.rank:
                    tied_participants.append(participant)
                else:
                    tied_participants = [participant]
                if len(tied_participants) > 1:
                    average_score = int(math.ceil(sum([float(self.score_by_rank(tied_rank)) for tied_rank in range(participant.rank, participant.rank + len(tied_participants))])/len(tied_participants)))
                    for tied_participant in tied_participants:
                        tied_participant.score = average_score + tied_participant.extra_point
            previous_participant = participant

    def print_scores(self):
        for participant in self.participants:
            print participant.score

participant_count = 0
contest = Contest()
while True:
    line = raw_input()
    if participant_count == 0:
        participant_count = int(line)
        continue
    args = [int(arg) for arg in line.split(' ')]
    contest.participants.append(Participant(*args))
    if len(contest.participants) == participant_count:
        break

    
contest.assign_scores()
contest.print_scores()
