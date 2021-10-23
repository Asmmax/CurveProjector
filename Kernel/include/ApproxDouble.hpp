#pragma once
#include <list>
#include <vector>

/**
 * Class defines a wrapper over double. 
 * The wrapper handles tolerance and implements logic for compute with tolerance.
 */
class ApproxDouble
{
private:
	double _value;
	double _tolerance;
public:

	/**
	* Constructor for the ApproxDouble class.
	*
	* @param value Value of type double.
	* 
	* @remarks Relative tolerance by default is around 2.2e-16.
	*/
	ApproxDouble(double value);

	/**
     * Constructor for the ApproxDouble class.
     *
     * @param value Value of type double.
	 * @param tolerance Absolute tolerance for the value.
     */
	ApproxDouble(double value, double tolerance);

	/**
     * Gives value.
     *
     * @return Reference to the current double value.
     */
	inline const double& value() const { return _value; }

	/**
     * Gives relative tolerance.
     *
     * @return Reference to the current relative tolerance as double.
     */
	inline const double epsilon() const { return _tolerance / _value; }

	/**
     * Gives absolute tolerance.
     *
     * @return Value of current absolute tolerance as double.
     */
	inline const double& tolerance() const { return _tolerance; }

	/**
	 * Checks if two values are equal within specified absolute tolerance.
	 * 
	 * @param left First value to compare.
	 * @param right Second value to compare.
	 * @param tolerance Absolute tolerance.
	 * @return true if values are equal and false otherwise.
	 *
	 * @remarks If the specified tolerance greater than sum tolerance of approx doubles,
	 * the specified tolerance will replace it.
	 */
	static bool equal(const ApproxDouble& left, const ApproxDouble& right, double tolerance);

	/**
     * Checks if first value less than second one within specified absolute tolerance.
	 *
	 * @param left First value to compare.
	 * @param right Second value to compare.
	 * @param tolerance Absolute tolerance.
	 * @return true if left less than right and false otherwise.
	 * 
	 * @remarks If the specified tolerance greater than sum tolerance of approx doubles, 
	 * the specified tolerance will replace it. 
	 */
	static bool less(const ApproxDouble& left, const ApproxDouble& right, double tolerance);

	/**
	 * Finds minimum values in sequence with specified absolute tolerance.
	 *
	 * @param values Set of values.
	 * @param tolerance Absolute tolerance.
	 * @return List of indices that correspond to the minimum values in the sequence.
	 */
	static std::list<unsigned int> min(const std::vector<ApproxDouble>& values, double tolerance);

	/**
     * Clamps current value in boundaries taking into account the tolerance.
     *
     * @param min Lower bound.
     * @param max Upper bound.
     * @return New clamped ApproxDouble object.
     */
	ApproxDouble clamp(double min, double max) const;

	/**
     * Checks if current value within tolerance greater than simple given value.
     *
     * @param right Given value.
     * @return true if current value greater than given value and flase otherwise.
     */
	bool operator>(const double& right) const;

	/**
	 * Checks if current value within tolerance less than simple given value.
	 *
	 * @param right Given value.
	 * @return true if current value less than given value and flase otherwise.
	 */
	bool operator<(const double& right) const;

	/**
     * Checks if current value within tolerance greater than given value within tolerance.
     *
     * @param right Given value.
     * @return true if current value greater than given value and flase otherwise.
     */
	bool operator>(const ApproxDouble& right) const;

	/**
     * Checks if current value within tolerance less than given value within tolerance.
     *
     * @param right Given value.
     * @return true if current value less than given value and flase otherwise.
     */
	bool operator<(const ApproxDouble& right) const;

	/**
     * Checks if current value within tolerance equal given value within tolerance.
     *
     * @param right Given value.
     * @return true if current value equal given value and flase otherwise.
     */
	bool operator==(const ApproxDouble& right) const;

	/**
     * Divides current approx value by given approx value.
     *
     * @param right Given value.
     * @return New divided ApproxDouble object.
     */
	ApproxDouble operator/(const ApproxDouble& right) const;
};
