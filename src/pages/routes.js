import {
  createBrowserRouter,
  createRoutesFromElements,
  Route
} from "react-router-dom";

import Root from './root/root';
import Dashboard from './dashboard/dashboard';

const router = createBrowserRouter(
    createRoutesFromElements(
      <Route path="/" element={<Root />}>
        <Route path="dashboard" element={<Dashboard />} />
        {/* ... etc. */}
      </Route>
    )
);

export default router;
  