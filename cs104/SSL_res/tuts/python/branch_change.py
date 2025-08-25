# This is a dictionary to store the min criteria to branch change into the 
# different departments. The keys are the departments and the values are the
# min cpi required to branch change into that department.
cpi_criteria = {
    "CSE" : 9.5,
    "EE" : 9.0,
    "ME" : 8.5,
    "CE" : 8.0,
    "CHE" : 7.5,
    "ENV" : 7.0,
    "BSBE" : 6.5,
}

def check_min_criteria(dept_name, cpi):
    """
    Checks if the student is eligible to branch change into dept_name.
    Takes two arguments, dept_name and cpi, and returns True if the student
    is eligible, False otherwise.
    """
    if cpi >= cpi_criteria[dept_name]:
        return True
    else:
        return False

def branch_change(curr_cpi, branch_prefs):
    """
    Takes two arguments, curr_cpi and branch_prefs, and returns the department
    the student can branch change to, or None if the student cannot branch change.
    """
    for dept in branch_prefs:
        if dept not in list(cpi_criteria.keys()):
            # Invalid department name, hence skipping
            continue
        if check_min_criteria(dept, curr_cpi):
            return dept
    return None