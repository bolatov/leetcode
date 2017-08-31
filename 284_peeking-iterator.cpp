import java.util.*;

// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer> {

    private List<Integer> list;
    
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
        if (iterator != null && iterator.hasNext()) {
	        this.list = new LinkedList<>();
            while (iterator.hasNext()) {
                list.add(iterator.next());
            }
        }
	}

    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        if (list == null || list.isEmpty()) {
            throw new NoSuchElementException("PeekIterator is empty");
        }
        return list.get(0);
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    if (list == null || list.isEmpty()) {
            throw new NoSuchElementException("PeekIterator is empty");
        }
        return list.remove(0);
	}

	@Override
	public boolean hasNext() {
	    return list != null && !list.isEmpty();
	}
    
}
