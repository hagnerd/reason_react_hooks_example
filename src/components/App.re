type state = int;

type action =
  | Increment
  | Decrement
  | Reset;

let countReducer = (changeBy, reset, state, action) =>
  switch (action) {
  | Increment => state + changeBy
  | Decrement => state - changeBy
  | Reset => reset
  };

type f = {
  state,
  dispatch: action => unit,
};

let useCount = (~initialCount=0, ~changeBy=1, ()) => {
  let (state, dispatch) =
    React.useReducer(countReducer(changeBy, initialCount), initialCount);
  {state, dispatch};
  /* (state, dispatch) */
};

/* let useCount = (~initialCount=0, ~changeBy=1, ()) => { */
/*   let (count, setCount) = React.useState(() => initialCount); */

/*   let increment = () => setCount(c => c + changeBy); */
/*   let decrement = () => setCount(c => c - changeBy); */
/*   let reset = () => setCount(_ => initialCount); */

/*   (count, increment, decrement, reset) */
/* }; */

[@react.component]
let make = () => {
  /* let (count, increment, decrement, reset) = useCount(()); */
  let {state, dispatch} = useCount();

  <>
    <div className="flex">
      <h2> {state->string_of_int |> React.string} </h2>
      <button onClick={_ => dispatch(Increment)}>
        {"Increment" |> React.string}
      </button>
      <button onClick={_ => dispatch(Decrement)}>
        {"Decrement" |> React.string}
      </button>
      <button onClick={_ => dispatch(Reset)}>
        {"Reset" |> React.string}
      </button>
    </div>
  </>;
};
