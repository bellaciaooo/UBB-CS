
def make_copy(pachete):
    cpy = []
    for el in pachete:
        elem_curent = {}
        for key, value in el.items():
            elem_curent[key] = value
        cpy.append(elem_curent)

    return cpy

def save_for_undo( undo_list, pachete):
    """
    Salveaza starea curenta a listei din al doilea parametru pentru cand vom face undo
    :param undo_list: starile predecente ale listei date
    :param pachete: lista data
    :return:
    """
    undo_list.append(pachete)